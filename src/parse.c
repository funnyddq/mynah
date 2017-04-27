#include <config.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

int parse_file(char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t size = 0;
	ssize_t read;
	int ret = -1;

	file = fopen(filename, "r");
	if (file == NULL)
		return -1;

	while (1)
	{
		read = getline(&line, &size, file);
		if (read == -1)
		{
			free(line);
			fclose(file);
			return 0;
		}

		if (size > 0)
		{
	//		if (*(line + read - 1) != '\n')
	//			 (parse(line) == 1-1
		}
	}
	free(line);
	fclose(file);
	return 0;
}
