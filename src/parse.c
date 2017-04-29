#include <config.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "parse.h"
#include "line.h"

int
parse_file(const char *input, const char *output)
{
	FILE *fileInput, *fileOutput = NULL;
	char *line = NULL;
	size_t size = 0;
	ssize_t read;
	int ret = -1;

	fileInput = fopen(input, "r");
	if (fileInput == NULL)
		return 1;
	if (output != NULL)
	{
		fileOutput = fopen(output, "w");
		if (fileOutput == NULL)
		{
			fclose(fileInput);
			return 1;
		}
	}

	while (1)
	{
		read = getline(&line, &size, fileInput);
		if (read == -1 || read == 0)
		{
			free(line);
			if (fileOutput != NULL)
				fclose(fileOutput);
			fclose(fileInput);
			return 0;
		}

		delete_line_delimeter(line, (unsigned int) read);
		print_message(fileOutput, line, LINE_DELIMETER);
	}
	free(line);
	if (fileOutput != NULL)
		fclose(fileOutput);
	fclose(fileInput);
	return 0;
}

void
print_message(FILE *file, const char *message, const char *delimeter)
{
	if (message == NULL)
		return;

	if (delimeter == NULL)
	{
		if (file == NULL)
			printf("%s", message);
		else
			fprintf(file, "%s", message);
	}
	else
	{
		if (file == NULL)
			printf("%s%s", message, delimeter);
		else
			fprintf(file, "%s%s", message, delimeter);

	}

	return;
}
