import bitwise

class Field:
    """Class representing a field in an instruction"""

    def __init__(self, name):
        self.name = name
        self.locs = {}

    def set_instr_idx(self, field_idx, instr_idx):
        self.locs[field_idx] = instr_idx

    def get_instr_idx(self, field_idx):
        if field_idx in self.locs:
            return self.locs[field_idx]
        return -1

    def generate(self, value, length):
        result = 0
        for field_idx, instr_idx in self.locs.items():
            bit = bitwise.bit_get(value, field_idx)
            if (field_idx == -1):
                raise RuntimeError(f"Invalid bit position {field_idx} in {self.name}")
            result |= (bit << instr_idx)
        return bitwise.to_bytes(result, length)

class Instruction():
    """Class representing an instruction"""

    def __init__(self, arch, name):
        """Initializes the Instruction.

        Args:
            arch (str): The architecture name.
            name (str): The name of the instruction.
            opcode (bytes): The opcode of the instruction (always_0 | always_1)
            args (dict): Dictionary mapping argument names to their offsets
        """
        self.arch = arch
        self.name = name
        self.opcode = None
        self.fields = []

    def add_fields(self, *fields):
        self.fields += fields

    def set_opcode(self, opcode):
        if type(opcode) is not bytes:
            raise RuntimeError("opcode must be bytes object")
        self.opcode = opcode

    def assemble(self, args):
        """Assembles the instruction with the given arguments.

        Args:
            args (dict(int)): A map from argument name to value to assemble into the instruction

        Raises:
            RuntimeError: Mismatch between the number of arguments and the number of arguments in the template.

        Returns:
            int: Instruction encoding
        """

        if self.opcode is None:
            raise RuntimeError("Attempted to assemble an unsolved instruction")
        
        result = bitwise.to_int(self.opcode)
        for field in self.fields:
            field_bytes = field.generate(args[field.name], len(self.opcode))
            result |= bitwise.to_int(field_bytes)

        return result


    def to_c_function(self):
        n_bits = len(self.opcode) * 8
        
        result = f"static inline uint{n_bits}_t {self.arch}_{self.name}("
        for i, field in enumerate(self.fields):
            if (i == 0):
                result += f"uint{n_bits}_t {field.name}"
            else:
                result += f", uint{n_bits}_t {field.name}"

        result += ") {\n"

        for field in self.fields:
            result += f"    uint{n_bits}_t {field.name}_field = 0;\n"
            for field_idx, instr_idx in field.locs.items():
                result += f"    {field.name}_field |= (({field.name} >> {field_idx}) & 1) << {instr_idx};\n"
            result += "\n"

        result += f"    return 0x{bitwise.to_hex(self.opcode)}"

        for field in self.fields:
            result += f" | {field.name}_field"
        
        result += ";\n}"

        return result

