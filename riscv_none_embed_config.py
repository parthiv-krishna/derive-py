import os
import subprocess

from assembler import Assembler

output_file = "./riscv-none-embed-insts.h"

regex = r"@([a-zA-Z0-9]+):(-?[0-9]+)"

templates = [
    ("add", "add x@dst:5, x@src1:5, x@src2:5"),
    ("addi", "addi x@dst:5, x@src:5, @imm:-11"),
    ("sub", "sub x@dst:5, x@src1:5, x@src2:5"),
    ("and", "and x@dst:5, x@src1:5, x@src2:5"),
    ("or", "or x@dst:5, x@src1:5, x@src2:5"),
    ("lw", "lw x@dst:5, @offset:-11(x@addr:5)"),
    ("sw", "sw x@src:5, @offset:-11(x@addr:5)"),
    ("nop", "nop"),
]

test_cases = [
    ("add", {"dst": 0, "src1": 0, "src2": 0}, "add x0, x0, x0"),
    ("add", {"dst": 4, "src1": 12, "src2": 1}, "add x4, x12, x1"),
    ("addi", {"dst": 0, "src": 0, "imm": 0}, "addi x0, x0, 0"),
    ("addi", {"dst": 0, "src": 3, "imm": 212}, "addi x0, x3, 212"),
    ("sub", {"dst": 0, "src1": 0, "src2": 0}, "sub x0, x0, x0"),
    ("sub", {"dst": 4, "src1": 12, "src2": 1}, "sub x4, x12, x1"),
    ("lw", {"dst": 0, "offset": 0, "addr": 0}, "lw x0, 0(x0)"),
    ("lw", {"dst": 1, "offset": 1024, "addr": 25}, "lw x1, 1024(x25)"),
    ("sw", {"src": 0, "offset": 0, "addr": 0}, "sw x0, 0(x0)"),
    ("sw", {"src": 5, "offset": 290, "addr": 14}, "sw x5, 290(x14)"),
    ("nop", {}, "nop")
]

class RiscVNoneEmbedAssembler(Assembler):
    """riscv-none-embed assembler (for esp32-c3)"""

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
        retcode = subprocess.call(["riscv-none-embed-gcc", "-march=rv32im", "-c", self.asm_file, "-o", self.obj_file])
        if retcode != 0:
            raise RuntimeError(f"Error assembling instruction: `{instruction}`")

        # Link the object file into a binary
        retcode = subprocess.call(["riscv-none-embed-objcopy", self.obj_file, "-O", "binary", self.bin_file])
        if retcode != 0:
            raise RuntimeError(f"Error objcopying: `{self.obj_file}`")

        # Read the binary
        with open(self.bin_file, "rb") as f:
            binary = f.read()

        if (len(binary) not in [4]):
            raise RuntimeError(f"Expected 2 or 4 byte instruction but got {len(binary)} bytes!")

        # convert from little endian
        return bytes(reversed(binary))


    def cleanup(self):
        """Cleans up any temporary files created during the assembly process."""

        os.remove(self.asm_file)
        os.remove(self.obj_file)
        os.remove(self.bin_file)

    def arch(self):
        """Returns a string denoting the assembler architecture."""
        return "riscv"

asm = RiscVNoneEmbedAssembler({"memmap": "memmap",
                            "filepath": "./test"})
