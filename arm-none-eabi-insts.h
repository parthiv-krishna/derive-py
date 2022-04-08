static inline uint32_t arm_add(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 16;
    src1_field |= ((src1 >> 1) & 1) << 17;
    src1_field |= ((src1 >> 2) & 1) << 18;
    src1_field |= ((src1 >> 3) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 0;
    src2_field |= ((src2 >> 1) & 1) << 1;
    src2_field |= ((src2 >> 2) & 1) << 2;
    src2_field |= ((src2 >> 3) & 1) << 3;

    return 0xe0800000 | dst_field | src1_field | src2_field;
}

static inline uint32_t arm_add_imm(uint32_t dst, uint32_t src, uint32_t imm) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 16;
    src_field |= ((src >> 1) & 1) << 17;
    src_field |= ((src >> 2) & 1) << 18;
    src_field |= ((src >> 3) & 1) << 19;

    uint32_t imm_field = 0;
    imm_field |= ((imm >> 0) & 1) << 0;
    imm_field |= ((imm >> 1) & 1) << 1;
    imm_field |= ((imm >> 2) & 1) << 2;
    imm_field |= ((imm >> 3) & 1) << 3;
    imm_field |= ((imm >> 4) & 1) << 4;
    imm_field |= ((imm >> 5) & 1) << 5;
    imm_field |= ((imm >> 6) & 1) << 6;
    imm_field |= ((imm >> 7) & 1) << 7;

    return 0xe2800000 | dst_field | src_field | imm_field;
}

static inline uint32_t arm_add_lsl(uint32_t dst, uint32_t src1, uint32_t src2, uint32_t shift) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 16;
    src1_field |= ((src1 >> 1) & 1) << 17;
    src1_field |= ((src1 >> 2) & 1) << 18;
    src1_field |= ((src1 >> 3) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 0;
    src2_field |= ((src2 >> 1) & 1) << 1;
    src2_field |= ((src2 >> 2) & 1) << 2;
    src2_field |= ((src2 >> 3) & 1) << 3;

    uint32_t shift_field = 0;
    shift_field |= ((shift >> 0) & 1) << 7;
    shift_field |= ((shift >> 1) & 1) << 8;
    shift_field |= ((shift >> 2) & 1) << 9;
    shift_field |= ((shift >> 3) & 1) << 10;
    shift_field |= ((shift >> 4) & 1) << 11;

    return 0xe0800000 | dst_field | src1_field | src2_field | shift_field;
}

static inline uint32_t arm_sub(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 16;
    src1_field |= ((src1 >> 1) & 1) << 17;
    src1_field |= ((src1 >> 2) & 1) << 18;
    src1_field |= ((src1 >> 3) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 0;
    src2_field |= ((src2 >> 1) & 1) << 1;
    src2_field |= ((src2 >> 2) & 1) << 2;
    src2_field |= ((src2 >> 3) & 1) << 3;

    return 0xe0400000 | dst_field | src1_field | src2_field;
}

static inline uint32_t arm_sub_imm(uint32_t dst, uint32_t src, uint32_t imm) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 16;
    src_field |= ((src >> 1) & 1) << 17;
    src_field |= ((src >> 2) & 1) << 18;
    src_field |= ((src >> 3) & 1) << 19;

    uint32_t imm_field = 0;
    imm_field |= ((imm >> 0) & 1) << 0;
    imm_field |= ((imm >> 1) & 1) << 1;
    imm_field |= ((imm >> 2) & 1) << 2;
    imm_field |= ((imm >> 3) & 1) << 3;
    imm_field |= ((imm >> 4) & 1) << 4;
    imm_field |= ((imm >> 5) & 1) << 5;
    imm_field |= ((imm >> 6) & 1) << 6;
    imm_field |= ((imm >> 7) & 1) << 7;

    return 0xe2400000 | dst_field | src_field | imm_field;
}

static inline uint32_t arm_and(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 16;
    src1_field |= ((src1 >> 1) & 1) << 17;
    src1_field |= ((src1 >> 2) & 1) << 18;
    src1_field |= ((src1 >> 3) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 0;
    src2_field |= ((src2 >> 1) & 1) << 1;
    src2_field |= ((src2 >> 2) & 1) << 2;
    src2_field |= ((src2 >> 3) & 1) << 3;

    return 0xe0000000 | dst_field | src1_field | src2_field;
}

static inline uint32_t arm_or(uint32_t dst, uint32_t src1, uint32_t src2) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src1_field = 0;
    src1_field |= ((src1 >> 0) & 1) << 16;
    src1_field |= ((src1 >> 1) & 1) << 17;
    src1_field |= ((src1 >> 2) & 1) << 18;
    src1_field |= ((src1 >> 3) & 1) << 19;

    uint32_t src2_field = 0;
    src2_field |= ((src2 >> 0) & 1) << 0;
    src2_field |= ((src2 >> 1) & 1) << 1;
    src2_field |= ((src2 >> 2) & 1) << 2;
    src2_field |= ((src2 >> 3) & 1) << 3;

    return 0xe1800000 | dst_field | src1_field | src2_field;
}

static inline uint32_t arm_mov(uint32_t dst, uint32_t src) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 0;
    src_field |= ((src >> 1) & 1) << 1;
    src_field |= ((src >> 2) & 1) << 2;
    src_field |= ((src >> 3) & 1) << 3;

    return 0xe1a00000 | dst_field | src_field;
}

static inline uint32_t arm_mov_imm(uint32_t dst, uint32_t imm) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t imm_field = 0;
    imm_field |= ((imm >> 0) & 1) << 0;
    imm_field |= ((imm >> 1) & 1) << 1;
    imm_field |= ((imm >> 2) & 1) << 2;
    imm_field |= ((imm >> 3) & 1) << 3;
    imm_field |= ((imm >> 4) & 1) << 4;
    imm_field |= ((imm >> 5) & 1) << 5;
    imm_field |= ((imm >> 6) & 1) << 6;
    imm_field |= ((imm >> 7) & 1) << 7;

    return 0xe3a00000 | dst_field | imm_field;
}

static inline uint32_t arm_ldr(uint32_t dst, uint32_t addr) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t addr_field = 0;
    addr_field |= ((addr >> 0) & 1) << 16;
    addr_field |= ((addr >> 1) & 1) << 17;
    addr_field |= ((addr >> 2) & 1) << 18;
    addr_field |= ((addr >> 3) & 1) << 19;

    return 0xe5900000 | dst_field | addr_field;
}

static inline uint32_t arm_ldr_imm_off(uint32_t dst, uint32_t addr, uint32_t imm) {
    uint32_t dst_field = 0;
    dst_field |= ((dst >> 0) & 1) << 12;
    dst_field |= ((dst >> 1) & 1) << 13;
    dst_field |= ((dst >> 2) & 1) << 14;
    dst_field |= ((dst >> 3) & 1) << 15;

    uint32_t addr_field = 0;
    addr_field |= ((addr >> 0) & 1) << 16;
    addr_field |= ((addr >> 1) & 1) << 17;
    addr_field |= ((addr >> 2) & 1) << 18;
    addr_field |= ((addr >> 3) & 1) << 19;

    uint32_t imm_field = 0;
    imm_field |= ((imm >> 0) & 1) << 0;
    imm_field |= ((imm >> 1) & 1) << 1;
    imm_field |= ((imm >> 2) & 1) << 2;
    imm_field |= ((imm >> 3) & 1) << 3;
    imm_field |= ((imm >> 4) & 1) << 4;
    imm_field |= ((imm >> 5) & 1) << 5;
    imm_field |= ((imm >> 6) & 1) << 6;
    imm_field |= ((imm >> 7) & 1) << 7;

    return 0xe5900000 | dst_field | addr_field | imm_field;
}

static inline uint32_t arm_str(uint32_t src, uint32_t addr) {
    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 12;
    src_field |= ((src >> 1) & 1) << 13;
    src_field |= ((src >> 2) & 1) << 14;
    src_field |= ((src >> 3) & 1) << 15;

    uint32_t addr_field = 0;
    addr_field |= ((addr >> 0) & 1) << 16;
    addr_field |= ((addr >> 1) & 1) << 17;
    addr_field |= ((addr >> 2) & 1) << 18;
    addr_field |= ((addr >> 3) & 1) << 19;

    return 0xe5800000 | src_field | addr_field;
}

static inline uint32_t arm_str_imm_off(uint32_t src, uint32_t addr, uint32_t imm) {
    uint32_t src_field = 0;
    src_field |= ((src >> 0) & 1) << 12;
    src_field |= ((src >> 1) & 1) << 13;
    src_field |= ((src >> 2) & 1) << 14;
    src_field |= ((src >> 3) & 1) << 15;

    uint32_t addr_field = 0;
    addr_field |= ((addr >> 0) & 1) << 16;
    addr_field |= ((addr >> 1) & 1) << 17;
    addr_field |= ((addr >> 2) & 1) << 18;
    addr_field |= ((addr >> 3) & 1) << 19;

    uint32_t imm_field = 0;
    imm_field |= ((imm >> 0) & 1) << 0;
    imm_field |= ((imm >> 1) & 1) << 1;
    imm_field |= ((imm >> 2) & 1) << 2;
    imm_field |= ((imm >> 3) & 1) << 3;
    imm_field |= ((imm >> 4) & 1) << 4;
    imm_field |= ((imm >> 5) & 1) << 5;
    imm_field |= ((imm >> 6) & 1) << 6;
    imm_field |= ((imm >> 7) & 1) << 7;

    return 0xe5800000 | src_field | addr_field | imm_field;
}

static inline uint32_t arm_nop() {
    return 0xe320f000;
}

static inline uint32_t arm_bx(uint32_t reg) {
    uint32_t reg_field = 0;
    reg_field |= ((reg >> 0) & 1) << 0;
    reg_field |= ((reg >> 1) & 1) << 1;
    reg_field |= ((reg >> 2) & 1) << 2;
    reg_field |= ((reg >> 3) & 1) << 3;

    return 0xe12fff10 | reg_field;
}

static inline uint32_t arm_blx(uint32_t reg) {
    uint32_t reg_field = 0;
    reg_field |= ((reg >> 0) & 1) << 0;
    reg_field |= ((reg >> 1) & 1) << 1;
    reg_field |= ((reg >> 2) & 1) << 2;
    reg_field |= ((reg >> 3) & 1) << 3;

    return 0xe12fff30 | reg_field;
}

