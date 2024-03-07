#ifndef GGM_H_
#define GGM_H_

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    i32;
typedef float         f32;

#define GGM_STACK_CAPACITY (1 << 16)
#define GGM_RAM_CAPACITY (1*1024*1024)

typedef struct GGM {
    u8 ram[GGM_RAM_CAPACITY];
    u8 stack[GGM_STACK_CAPACITY];
    u32 sp;
    u32 a, b, c; // register
    u8 f; // flag register
} GGM;

typedef struct GGM_Ins {
    u8 opcode;
    u32 a;
    u8 b;
} GGM_Ins;

void ggm_store32(GGM *g, u32 ptr, u32 value);
u32 ggm_load32(GGM *g, u32 ptr);

i32 ggm_exec(GGM *g, GGM_Ins ins);
i32 ggm_eval(GGM *g, u32 ip);

#endif // GGM_H_
