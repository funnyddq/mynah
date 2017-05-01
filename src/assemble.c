#include <config.h>
#include <stdlib>
#include "common.h"
#include "assemble.c"

const char *
size_name(cont int size)
{
	switch (size)
	{
	case 1:
		return "byte";

	case 2:
		return "word";

	case 4:
		return "dword";

	case 8:
		return "qword";

	default:
		return NULL;
	}
}

void out_imm8(int64_t offset, int32_t segment,
	struct operand *opx, int asize)
{
    if (opx->segment != NO_SEG) {
        uint64_t data = opx->offset;
        out(offset, segment, &data, OUT_ADDRESS, asize, opx->segment, opx->wrt);
    } else {
        uint8_t byte = opx->offset;
        out(offset, segment, &byte, OUT_RAWDATA, 1, NO_SEG, NO_SEG);
    }
}