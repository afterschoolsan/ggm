#include <stdio.h>
#include <stdlib.h>
#include "ggm.h"

int main(void)
{
    GGM *g = malloc(sizeof(GGM));
    GGM_Ins ins;
    ins.opcode = 0xFF;
    ggm_exec(g, ins);
    return 0;
}
