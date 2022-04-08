import os
import subprocess

from assembler import Assembler

output_file = "./arm-none-eabi-insts.h"

regex = r"@([a-zA-Z0-9]+):(-?[0-9]+)"

templates = [
    ("add", "add r@dst:4, r@src1:4, r@src2:4"),
    ("add_imm", "add r@dst:4, r@src:4, #@imm:8"),
    ("add_lsl", "add r@dst:4, r@src1:4, r@src2:4, LSL #@shift:5"),
    ("sub", "sub r@dst:4, r@src1:4, r@src2:4"),
    ("sub_imm", "sub r@dst:4, r@src:4, #@imm:8"),
    ("and", "and r@dst:4, r@src1:4, r@src2:4"),
    ("or", "orr r@dst:4, r@src1:4, r@src2:4"),
    ("mov", "mov r@dst:4, r@src:4"),
    ("mov_imm", "mov r@dst:4, #@imm:8"),
    ("ldr", "ldr r@dst:4, [r@addr:4]"),
    ("ldr_imm_off", "ldr r@dst:4, [r@addr:4, #@imm:8]"),
    ("str", "str r@src:4, [r@addr:4]"),
    ("str_imm_off", "str r@src:4, [r@addr:4, #@imm:8]"),
    ("nop", "nop"),
    ("bx", "bx r@reg:4"),
    ("blx", "blx r@reg:4"),
]

test_cases = [
    ("add", {"dst": 0, "src1": 0, "src2": 0}, "add r0, r0, r0"),
    ("add", {"dst": 4, "src1": 12, "src2": 1}, "add r4, r12, r1"),
    ("add_imm", {"dst": 0, "src": 0, "imm": 0}, "add r0, r0, #0"),
    ("add_imm", {"dst": 5, "src": 3, "imm": 212}, "add r5, r3, #212"),
    ("add_lsl", {"dst": 0, "src1": 0, "src2": 0, "shift": 0}, "add r0, r0, r0, LSL #0"),
    ("add_lsl", {"dst": 1, "src1": 4, "src2": 1, "shift": 20}, "add r1, r4, r1, LSL #20"),
    ("sub", {"dst": 0, "src1": 0, "src2": 0}, "sub r0, r0, r0"),
    ("sub", {"dst": 3, "src1": 2, "src2": 1}, "sub r3, r2, r1"),
    ("sub_imm", {"dst": 0, "src": 0, "imm": 0}, "sub r0, r0, #0"),
    ("sub_imm", {"dst": 8, "src": 2, "imm": 82}, "sub r8, r2, #82"),
    ("and", {"dst": 0, "src1": 0, "src2": 0}, "and r0, r0, r0"),
    ("and", {"dst": 1, "src1": 2, "src2": 3}, "and r1, r2, r3"),
    ("or", {"dst": 0, "src1": 0, "src2": 0}, "orr r0, r0, r0"),
    ("or", {"dst": 4, "src1": 5, "src2": 7}, "orr r4, r5, r7"),
    ("mov", {"dst": 0, "src": 0}, "mov r0, r0"),
    ("mov", {"dst": 5, "src": 10}, "mov r5, r10"),
    ("mov_imm", {"dst": 0, "imm": 0}, "mov r0, #0"),
    ("mov_imm", {"dst": 2, "imm": 91}, "mov r2, #91"),
    ("ldr", {"dst": 0, "addr": 0}, "ldr r0, [r0]"),
    ("ldr", {"dst": 9, "addr": 2}, "ldr r9, [r2]"),
    ("ldr_imm_off", {"dst": 0, "addr": 0, "imm": 0}, "ldr r0, [r0, #0]"),
    ("ldr_imm_off", {"dst": 1, "addr": 2, "imm": 3}, "ldr r1, [r2, #3]"),
    ("str", {"src": 0, "addr": 0}, "str r0, [r0]"),
    ("str", {"src": 3, "addr": 0}, "str r3, [r0]"),
    ("str_imm_off", {"src": 0, "addr": 0, "imm": 0}, "str r0, [r0, #0]"),
    ("str_imm_off", {"src": 5, "addr": 0, "imm": 14}, "str r5, [r0, #14]"),
    ("nop", {}, "nop"),
    ("bx", {"reg": 0}, "bx r0"),
    ("bx", {"reg": 8}, "bx r8"),
    ("blx", {"reg": 0}, "blx r0"),
    ("blx", {"reg": 5}, "blx r5"),
]

class ArmNoneEabiAssembler(Assembler):
    """arm-none-eabi assembler (for r/pi)"""

    def __init__(self, config_dict):
        """Sets up an instance of an ArmNoneEabiAssembler.
        
        Args:
            config_dict: A dictionary containing the assembler configuration.
        """

        self.memmap = config_dict["memmap"]
        self.asm_file = config_dict["filepath"] + ".S"
        self.obj_file = config_dict["filepath"] + ".o"
        self.bin_file = config_dict["filepath"] + ".bin"


    def assemble(self, instruction):
        """Assembles a given file and returns the resulting binary.

        Args:
            filename (str): The name of the file to assemble.

        Returns:
            bytes: The assembled binary.
        """

        # Create temporary assembly file
        with open(self.asm_file, "w+") as f:
            f.write(instruction + "\n")

        
        # Assemble the file
        retcode = subprocess.call(["arm-none-eabi-as", "--warn", "-mcpu=arm1176jzf-s", "-march=armv6zk", self.asm_file, "-o", self.obj_file])
        if retcode != 0:
            raise RuntimeError(f"Error assembling instruction: `{instruction}`")

        # Link the object file into a binary
        retcode = subprocess.call(["arm-none-eabi-objcopy", self.obj_file, "-O", "binary", self.bin_file])
        if retcode != 0:
            raise RuntimeError(f"Error objcopying: `{self.obj_file}`")

        # Read the binary
        with open(self.bin_file, "rb") as f:
            binary = f.read()

        if (len(binary) != 4):
            raise RuntimeError(f"Expected 4 byte instruction but got {len(binary)} bytes!")

        # convert from little endian
        return bytes([binary[3], binary[2], binary[1], binary[0]])


    def cleanup(self):
        """Cleans up any temporary files created during the assembly process."""

        os.remove(self.asm_file)
        os.remove(self.obj_file)
        os.remove(self.bin_file)

    def arch(self):
        """Returns a string denoting the assembler architecture."""
        return "arm"

asm = ArmNoneEabiAssembler({"memmap": "memmap",
                            "filepath": "./test"})
