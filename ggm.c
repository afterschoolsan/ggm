#include "ggm.h"
#include <stdio.h>

typedef struct GGM_Buffer {
    u8 *items;
    u32 count, capacity;
} GGM_Buffer;

typedef struct GGM_Label {
    char name[0xFF];
    u32 length;
} GGM_Label;

typedef struct GGM_Module {
    struct {
        GGM_Label *items;
        u32 count, capacity;
    } labels;
    GGM_Buffer buffer;
} GGM_Module;

void ggm_store32(GGM *g, u32 ptr, u32 value)
{
    g->ram[ptr + 0] = value;
    g->ram[ptr + 1] = value;
    g->ram[ptr + 2] = value;
    g->ram[ptr + 3] = value;
}

u32 ggm_load32(GGM *g, u32 ptr)
{
    u8 v0 = g->ram[ptr + 0];
    u8 v1 = g->ram[ptr + 1];
    u8 v2 = g->ram[ptr + 2];
    u8 v3 = g->ram[ptr + 3];
    return (u32)(v0);
}

i32 ggm_fetch_ins(GGM *g, u32 ip, GGM_Ins *inst)
{
    return -1;
}

i32 ggm_eval(GGM *g, u32 ip)
{
#define NOT_HALT(pGGM) ((pGGM)->f != 0)
    while(NOT_HALT(g)) {
        GGM_Ins inst;
        i32 r = ggm_fetch_ins(g, ip, &inst);
        if(r < 0) return -1;
        r = ggm_exec(g, inst);
        if(r < 0) return -1;
    }
#undef NOT_HALT
    return 0;
}

i32 ggm_exec(GGM *g, GGM_Ins ins)
{
    switch(ins.opcode){
        /** BRK */
        case 0x00: 
            {
                g->f = 0;
            } break;
        /** DUMP */
        case 0xFF:
            {
                printf("STATE: a:0x%x, b:0x%x, c:0x%x", g->a, g->b, g->c);
            } break;
        default:
            break;
    }
    return 0;
}
