#include <config.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "parse.h"

int parse_file(char *input, char *output)
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
		if (read == -1)
		{
			free(line);
			if (fileOutput != NULL)
				fclose(fileOutput);
			fclose(fileInput);
			return 0;
		}

		if (size > 0)
		{
			if (*(line + read - 1) != '\n')
				print_message(fileOutput, line);
			else
			{
				if (size >= 2)
				{
					if (*(line + read - 2) == '\\')
						*(line + read - 2) = 0;
					print_message(fileOutput, line);
				}
			}
		}
	}
	free(line);
	if (fileOutput != NULL)
		fclose(fileOutput);
	fclose(fileInput);
	return 0;
}

void print_message(FILE *file, char *message)
{
	if (message == NULL)
		return;

	if (file == NULL)
		printf("%s", message);
	else
		fprintf(file, "%s", message);

	return;
}