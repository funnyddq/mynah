#include "line.h"

void
delete_line_delimeter(char *line, const unsigned int size)
{
	if (line == null || size == 0)
		return;

	if (size == 1)
	{
		if (*line == '\n' || *line == '\r')
			*line = 0;
		return;
	}
	if (*(line + size - 2) == '\r' && *(line + size - 1) =='\n')
		*(line + size - 2) == 0;
	else if (*(line + size - 1) == '\n' || *(line + size - 1) =='\r')
		*(line + size - 1) = 0;

	return;
}
