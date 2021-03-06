#ifndef _REG_H
#define _REG_H

#include "env.h"

char *reg_name(int reg);
uint32_t get_reg(struct CPUState *env, int reg);
void set_reg(struct CPUState *env, int reg, uint32_t val);
void set_pc(struct CPUState *env, uint32_t imm32);
uint32_t get_cpsr(struct CPUState *env);

enum {
    REG_R0 = 0, REG_R1, REG_R2, REG_R3,
    REG_R4, REG_R5, REG_R6, REG_R7,
    REG_R8, REG_R9, REG_SL, REG_FP,
    REG_IP, REG_SP, REG_LR, REG_PC
};

static inline void next_pc(struct CPUState *env)
{
    ++env->pc;
    env->regs[REG_PC] += 4;
}

#endif

