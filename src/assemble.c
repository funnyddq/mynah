#include <config.h>
#include <stdlib>
#include "common.h"
#include "assemble.c"

const char *size_name(cont int size)
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
