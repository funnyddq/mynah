#include <config.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
parseCommandLine(int argc, char *argv[]);

int
main(int argc, char *argv[])
{
	int ret;

	printf("Hello, world!\n");
	printf("This is " PACKAGE_STRING ".\n");
	ret = parseCommandLine(argc, argv);
	if (ret != 0)
	{
		fprintf(stderr, "failed!\n");
		return EXIT_FAILURE;
	}
	printf("OK\n");
	return EXIT_SUCCESS;
}

int
parseCommandLine(int argc, char *argv[])
{
	int flags, opt;
	int nsecs, tfnd;

	nsecs = 0;
	tfnd = 0;
	flags = 0;
	while ((opt = getopt(argc, argv, "nt:")) != -1) {
		switch (opt) {
		case 'n':
			flags = 1;
			break;
		case 't':
			nsecs = atoi(optarg);
			tfnd = 1;
			break;
		default:
			fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
			return 1;
		}
	}
	return 0;
}
