static inline uint32_t arm_add(uint32_t dst, uint32_t src1, uint32_t src2) {
    return 0xe0800000 |
           (dst << 12) |
           (src1 << 16) |
           (src2 << 0);
}

static inline uint32_t arm_add_imm(uint32_t dst, uint32_t src, uint32_t imm) {
    return 0xe2800000 |
           (dst << 12) |
           (src << 16) |
           (imm << 0);
}

static inline uint32_t arm_add_lsl(uint32_t dst, uint32_t src1, uint32_t src2, uint32_t shift) {
    return 0xe0800000 |
           (dst << 12) |
           (src1 << 16) |
           (src2 << 0) |
           (shift << 7);
}

static inline uint32_t arm_sub(uint32_t dst, uint32_t src1, uint32_t src2) {
    return 0xe0400000 |
           (dst << 12) |
           (src1 << 16) |
           (src2 << 0);
}

static inline uint32_t arm_sub_imm(uint32_t dst, uint32_t src, uint32_t imm) {
    return 0xe2400000 |
           (dst << 12) |
           (src << 16) |
           (imm << 0);
}

static inline uint32_t arm_and(uint32_t dst, uint32_t src1, uint32_t src2) {
    return 0xe0000000 |
           (dst << 12) |
           (src1 << 16) |
           (src2 << 0);
}

static inline uint32_t arm_or(uint32_t dst, uint32_t src1, uint32_t src2) {
    return 0xe1800000 |
           (dst << 12) |
           (src1 << 16) |
           (src2 << 0);
}

static inline uint32_t arm_mov_reg(uint32_t dst, uint32_t src) {
    return 0xe1a00000 |
           (dst << 12) |
           (src << 0);
}

static inline uint32_t arm_mov_imm(uint32_t dst, uint32_t imm) {
    return 0xe3a00000 |
           (dst << 12) |
           (imm << 0);
}

static inline uint32_t arm_ldr(uint32_t dst, uint32_t addr) {
    return 0xe5900000 |
           (dst << 12) |
           (addr << 16);
}

static inline uint32_t arm_ldr_imm_off(uint32_t dst, uint32_t addr, uint32_t offset) {
    return 0xe5900000 |
           (dst << 12) |
           (addr << 16) |
           (offset << 0);
}

static inline uint32_t arm_str(uint32_t src, uint32_t addr) {
    return 0xe5800000 |
           (src << 12) |
           (addr << 16);
}

static inline uint32_t arm_str_imm_off(uint32_t src, uint32_t addr, uint32_t offset) {
    return 0xe5800000 |
           (src << 12) |
           (addr << 16) |
           (offset << 0);
}

static inline uint32_t arm_nop() {
    return 0xe320f000;
}

static inline uint32_t arm_bx(uint32_t reg) {
    return 0xe12fff10 |
           (reg << 0);
}

static inline uint32_t arm_blx(uint32_t reg) {
    return 0xe12fff30 |
           (reg << 0);
}

