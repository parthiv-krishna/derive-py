#include <stdio.h>

typedef int uint32_t;

static inline uint32_t riscv_add(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 7;
    dst_field |= ((dst >> 1) & 1) << 8;
    dst_field |= ((dst >> 2) & 1) << 9;
    dst_field |= ((dst >> 3) & 1) << 10;
    dst_field |= ((dst >> 4) & 1) << 11;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 15;
    src1_field |= ((src1 >> 1) & 1) << 16;
    src1_field |= ((src1 >> 2) & 1) << 17;
    src1_field |= ((src1 >> 3) & 1) << 18;
    src1_field |= ((src1 >> 4) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 20;
    src2_field |= ((src2 >> 1) & 1) << 21;
    src2_field |= ((src2 >> 2) & 1) << 22;
    src2_field |= ((src2 >> 3) & 1) << 23;
    src2_field |= ((src2 >> 4) & 1) << 24;

    return 0x33 | dst_field | src1_field | src2_field;
}

static inline uint32_t riscv_addi(uint32_t dst, uint32_t src, uint32_t imm) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 7;
    dst_field |= ((dst >> 1) & 1) << 8;
    dst_field |= ((dst >> 2) & 1) << 9;
    dst_field |= ((dst >> 3) & 1) << 10;
    dst_field |= ((dst >> 4) & 1) << 11;

    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 15;
    src_field |= ((src >> 1) & 1) << 16;
    src_field |= ((src >> 2) & 1) << 17;
    src_field |= ((src >> 3) & 1) << 18;
    src_field |= ((src >> 4) & 1) << 19;

    uint32_t imm_field = 0;
    imm_field |= ((imm >> 0) & 1) << 20;
    imm_field |= ((imm >> 1) & 1) << 21;
    imm_field |= ((imm >> 2) & 1) << 22;
    imm_field |= ((imm >> 3) & 1) << 23;
    imm_field |= ((imm >> 4) & 1) << 24;
    imm_field |= ((imm >> 5) & 1) << 25;
    imm_field |= ((imm >> 6) & 1) << 26;
    imm_field |= ((imm >> 7) & 1) << 27;
    imm_field |= ((imm >> 8) & 1) << 28;
    imm_field |= ((imm >> 9) & 1) << 29;
    imm_field |= ((imm >> 10) & 1) << 30;
    imm_field |= ((imm >> 11) & 1) << 31;

    return 0x13 | dst_field | src_field | imm_field;
}

static inline uint32_t riscv_sub(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 7;
    dst_field |= ((dst >> 1) & 1) << 8;
    dst_field |= ((dst >> 2) & 1) << 9;
    dst_field |= ((dst >> 3) & 1) << 10;
    dst_field |= ((dst >> 4) & 1) << 11;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 15;
    src1_field |= ((src1 >> 1) & 1) << 16;
    src1_field |= ((src1 >> 2) & 1) << 17;
    src1_field |= ((src1 >> 3) & 1) << 18;
    src1_field |= ((src1 >> 4) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 20;
    src2_field |= ((src2 >> 1) & 1) << 21;
    src2_field |= ((src2 >> 2) & 1) << 22;
    src2_field |= ((src2 >> 3) & 1) << 23;
    src2_field |= ((src2 >> 4) & 1) << 24;

    return 0x40000033 | dst_field | src1_field | src2_field;
}

static inline uint32_t riscv_and(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 7;
    dst_field |= ((dst >> 1) & 1) << 8;
    dst_field |= ((dst >> 2) & 1) << 9;
    dst_field |= ((dst >> 3) & 1) << 10;
    dst_field |= ((dst >> 4) & 1) << 11;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 15;
    src1_field |= ((src1 >> 1) & 1) << 16;
    src1_field |= ((src1 >> 2) & 1) << 17;
    src1_field |= ((src1 >> 3) & 1) << 18;
    src1_field |= ((src1 >> 4) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 20;
    src2_field |= ((src2 >> 1) & 1) << 21;
    src2_field |= ((src2 >> 2) & 1) << 22;
    src2_field |= ((src2 >> 3) & 1) << 23;
    src2_field |= ((src2 >> 4) & 1) << 24;

    return 0x7033 | dst_field | src1_field | src2_field;
}

static inline uint32_t riscv_or(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 7;
    dst_field |= ((dst >> 1) & 1) << 8;
    dst_field |= ((dst >> 2) & 1) << 9;
    dst_field |= ((dst >> 3) & 1) << 10;
    dst_field |= ((dst >> 4) & 1) << 11;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 15;
    src1_field |= ((src1 >> 1) & 1) << 16;
    src1_field |= ((src1 >> 2) & 1) << 17;
    src1_field |= ((src1 >> 3) & 1) << 18;
    src1_field |= ((src1 >> 4) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 20;
    src2_field |= ((src2 >> 1) & 1) << 21;
    src2_field |= ((src2 >> 2) & 1) << 22;
    src2_field |= ((src2 >> 3) & 1) << 23;
    src2_field |= ((src2 >> 4) & 1) << 24;

    return 0x6033 | dst_field | src1_field | src2_field;
}

static inline uint32_t riscv_lw(uint32_t dst, uint32_t offset, uint32_t addr) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 7;
    dst_field |= ((dst >> 1) & 1) << 8;
    dst_field |= ((dst >> 2) & 1) << 9;
    dst_field |= ((dst >> 3) & 1) << 10;
    dst_field |= ((dst >> 4) & 1) << 11;

    uint32_t offset_field = 0;
    offset_field |= ((offset >> 0) & 1) << 20;
    offset_field |= ((offset >> 1) & 1) << 21;
    offset_field |= ((offset >> 2) & 1) << 22;
    offset_field |= ((offset >> 3) & 1) << 23;
    offset_field |= ((offset >> 4) & 1) << 24;
    offset_field |= ((offset >> 5) & 1) << 25;
    offset_field |= ((offset >> 6) & 1) << 26;
    offset_field |= ((offset >> 7) & 1) << 27;
    offset_field |= ((offset >> 8) & 1) << 28;
    offset_field |= ((offset >> 9) & 1) << 29;
    offset_field |= ((offset >> 10) & 1) << 30;
    offset_field |= ((offset >> 11) & 1) << 31;

    uint32_t addr_field = 0;
    addr_field |= ((addr >> 0) & 1) << 15;
    addr_field |= ((addr >> 1) & 1) << 16;
    addr_field |= ((addr >> 2) & 1) << 17;
    addr_field |= ((addr >> 3) & 1) << 18;
    addr_field |= ((addr >> 4) & 1) << 19;

    return 0x2003 | dst_field | offset_field | addr_field;
}

static inline uint32_t riscv_sw(uint32_t src, uint32_t offset, uint32_t addr) {
    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 20;
    src_field |= ((src >> 1) & 1) << 21;
    src_field |= ((src >> 2) & 1) << 22;
    src_field |= ((src >> 3) & 1) << 23;
    src_field |= ((src >> 4) & 1) << 24;

    uint32_t offset_field = 0;
    offset_field |= ((offset >> 0) & 1) << 7;
    offset_field |= ((offset >> 1) & 1) << 8;
    offset_field |= ((offset >> 2) & 1) << 9;
    offset_field |= ((offset >> 3) & 1) << 10;
    offset_field |= ((offset >> 4) & 1) << 11;
    offset_field |= ((offset >> 5) & 1) << 25;
    offset_field |= ((offset >> 6) & 1) << 26;
    offset_field |= ((offset >> 7) & 1) << 27;
    offset_field |= ((offset >> 8) & 1) << 28;
    offset_field |= ((offset >> 9) & 1) << 29;
    offset_field |= ((offset >> 10) & 1) << 30;
    offset_field |= ((offset >> 11) & 1) << 31;

    uint32_t addr_field = 0;
    addr_field |= ((addr >> 0) & 1) << 15;
    addr_field |= ((addr >> 1) & 1) << 16;
    addr_field |= ((addr >> 2) & 1) << 17;
    addr_field |= ((addr >> 3) & 1) << 18;
    addr_field |= ((addr >> 4) & 1) << 19;

    return 0x2023 | src_field | offset_field | addr_field;
}

static inline uint32_t riscv_nop() {
    return 0x13;
}

int main() {
    volatile int i = 0;
    printf("%x\n", riscv_sw(32, 12, 19));
}