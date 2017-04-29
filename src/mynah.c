#include <config.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "mynah.h"
#include "parse.h"

static const char *optstring = "ho:v";
static const struct option longopts[] = {
	{"help", no_argument, 0, 'h'},
	{"version", no_argument, 0, 'v'},
	{0, 0, 0, 0}
};

static int is_help_set = 0;
static int is_output_set = 0;
static char *arg_output = NULL;
static int is_version_set = 0;

int
main(int argc, char *argv[])
{
	int ret;
	char *input = NULL;

	ret = parse_command_line(argc, argv);
	if (ret != 0)
	{
		usage();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int
parse_command_line(int argc, char * argv[])
{
	int ret;
	int longindex;

	opterr = 0;
	while (1)
	{
		ret = getopt_long(argc, argv, optstring, longopts, &longindex);
		if (ret == -1)
			break;

		switch (ret)
		{
		case 'h':
			if (argc != 2)
				return 1;
			show_help();
			return 0;

		case 'v':
			if (argc != 2)
				return 1;
			show_version();
			return 0;

		case 'o':
			is_output_set = 1;
			arg_output = optarg;
			break;

		default:
			return 1;
		}
	}

	if (optind != argc - 1)
		return 1;

	ret = parse_file(argv[optind], arg_output);
	return ret;
}

void
usage()
{
	show_help();
	return;
}

void
show_help()
{
	printf("Usage:\n\tmynah [Option] file\n");
	return;
}

void
show_version()
{
	printf("mynah versijon 0.0.1\n");
	return;
}
