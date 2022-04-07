import importlib
import re
import argparse

import bitwise
from instruction import Instruction, Field

def solve_instruction(asm, instr_name, template, regex):
    """Solves a template and prints the resulting assembly.
    
    Args:
        asm (Assembler): The assembler to use.
        instr_name (str): The name of the instruction.
        template (str): The template to solve.
        regex (str): The regular expression to use to match the template arguments.

    Returns:
        Instruction: The instruction that was solved from the given information.
    """

    instruction = Instruction(asm.arch(), instr_name)

    matches = list(re.finditer(regex, template))
    # field_widths = {match.group(1): int(match.group(2)) for match in matches}

    # for instruction as a whole
    instr_always_0 = None
    instr_always_1 = None

    if len(matches) == 0:
        # no arguments
        binary = asm.assemble(template)
        instr_always_1 = binary

    # iterate through each matched location in the template
    for i in range(len(matches)):
                

        curr_match = matches[i]

        field_name = curr_match.group(1)
        field_width = int(curr_match.group(2))

        # for the current field
        field_always_0 = None
        field_always_1 = None

        # stores the binary for each bit_pos
        encodings = []

        for bit_pos in range(field_width):
            value = 1 << bit_pos

            # insert current option into selected location, zero everything else
            filled_template = template[:curr_match.start()] + str(value) + template[curr_match.end():]
            filled_template = re.sub(regex, "0", filled_template)
            
            # # generate binary for instruction
            binary = asm.assemble(filled_template)

            # setup always_0 and always_1 to match length of instruction
            if instr_always_0 is None:
                instr_always_0 = bytes([0xFF for i in range(len(binary))])
                instr_always_1 = bytes([0xFF for i in range(len(binary))])
            if field_always_0 is None:
                field_always_0 = bytes([0xFF for i in range(len(binary))])
                field_always_1 = bytes([0xFF for i in range(len(binary))])


            field_always_0 = bitwise.AND(field_always_0, bitwise.NOT(binary))
            field_always_1 = bitwise.AND(field_always_1, binary)

            encodings.append(binary)

        both_0_and_1 = bitwise.AND(field_always_0, field_always_1) 
        if (bitwise.to_int(both_0_and_1) != 0):
            raise RuntimeError(f"Impossible, some bits are both always 0 and 1: {both_0_and_1}")

        field_unchanged = bitwise.OR(field_always_0, field_always_1)
        field_bits = bitwise.NOT(field_unchanged)
        
        field = Field(field_name)

        for field_idx in range(field_width):
            one_hot = bitwise.AND(field_bits, encodings[field_idx])
            instr_idx = bitwise.FFS(one_hot)
            field.set_instr_idx(field_idx, instr_idx)
        
        instruction.add_fields(field)

        instr_always_0 = bitwise.AND(instr_always_0, field_always_0)
        instr_always_1 = bitwise.AND(instr_always_1, field_always_1)

    instruction.set_opcode(instr_always_1)

    return instruction

def test_instruction(asm, instr: Instruction, args, assembly):
    """Tests a single instruction's solved encoding against the expected encoding.

    Args:
        asm (Assembler): The assembler to use.
        instr (Instruction): The instruction to test. 
        args (list): The arguments to use in the instruction.
        assembly (str): The assembly to use as ground truth.

    Raises:
        RuntimeError: _description_
    """
    for field in instr.fields:
        if field.name not in args:
            raise RuntimeError(f"Bad test {assembly}: {field.name} not found in args")

    actual = instr.assemble(args)
    expected = bitwise.to_int(asm.assemble(assembly))
    if actual != expected:
        raise RuntimeError(f"{assembly} failed: Got {actual:x} but expected {expected:x}")

def main(config):
    # Assembler object that gives .assemble and .cleanup methods
    asm = config.asm
    # List of (instr_name, template, list of argument names)
    templates = config.templates
    # Regular expression to match arguments in templates
    regex = config.regex
    # Output header file
    output_file = config.output_file
    # List of (instr_name, arguments, expected encoding)
    test_cases = config.test_cases

    # {instr_name: Instruction}
    solved = {}

    # Solve instructions
    for instr_name, template in templates:
        if instr_name in solved:
            raise RuntimeError(f"Duplicate instruction name: {instr_name}")
        print(f"Solving {instr_name}")
        solved[instr_name] = solve_instruction(asm, instr_name, template, regex)

    # Test instructions
    print(f"Running test cases")
    for instr_name, args, assembly in test_cases:
        if instr_name not in solved:
            raise RuntimeError(f"{instr_name} not found in solved instructions")
        test_instruction(asm, solved[instr_name], args, assembly)

    print(f"Successfully ran {len(test_cases)} test cases")

    # Write output
    with open(output_file, "w") as f:
        for instr in solved.values():
            f.write(instr.to_c_function())
            f.write("\n\n")
    print(f"Wrote {len(solved)} instructions to {output_file}")

    asm.cleanup()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Derive assembly instructions.")
    parser.add_argument("config", help="The configuration python file to use (without .py).")
    args = parser.parse_args()

    config = importlib.import_module(args.config)

    main(config)