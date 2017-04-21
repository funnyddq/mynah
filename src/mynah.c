#include <config.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "mynah.h"

static int is_a_set = 0;
static int is_b_set = 0;
static int is_c_set = 0;
static int is_d_set = 0;
static int is_add_set = 0;
static int is_append_set = 0;
static int is_help_set = 0;
static int is_verbose_set = 0;
static int is_version_set = 0;

static const char *optstring = "a:b:c:d";
static const struct option longopts[] = {
	{"add", required_argument, 0, 1},
	{"append", no_argument, 0, 2},
	{"help", no_argument, 0, 3},
	{"verbose", no_argument, 0, 4},
	{"version", no_argument, 0, 5},
	{0, 0, 0, 0}
};
	
int
main(int argc, char *argv[])
{
	int ret;

	printf("This is " PACKAGE_STRING ".\n");
	ret = parse_command_line(argc, argv);
	if (ret != 0)
	{
		fprintf(stderr, "failed!\n");
		return EXIT_FAILURE;
	}
	printf("OK\n");
	return EXIT_SUCCESS;
}

int
parse_command_line(int argc, char * argv[])
{
	int ret;
	int longindex;

	printf("optarg = %s\n", optarg);
	printf("optind = %d\n", optind);
	printf("opterr = %d\n", opterr);
	printf("optopt = %d\n", optopt);
	printf("optopt = %c\n", optopt);
	while (1) {
		ret = getopt_long(argc, argv, optstring, longopts, &longindex);
	printf("+++++++++++++++++++++++++\n");
	printf("ret = %d\n", ret);
	printf("ret = %c\n", ret);
	printf("optopt = %c\n", optopt);
	printf("optarg = %s\n", optarg);
	printf("optind = %d\n", optind);
	printf("opterr = %d\n", opterr);
	printf("optopt = %d\n", optopt);
	printf("optopt = %c\n", optopt);
		if (ret == -1)
			break;

		switch (ret) {
		case 0:
			printf("option %s", longopts[longindex].name);
			if (optarg)
				printf(" with arg %s\n", optarg);
			break;

		case 'a':
			printf("-a set\n");
			break;

		case 'b':
			printf("-b set\n");
			break;

		case 'c':
			printf("-c set\n");
			break;

		case 'd':
			printf("-d set\n");
			break;

		case 1:
			printf("--add set\n");
			break;

		case 2:
			printf("--append set\n");
			break;

		case 3:
			printf("--help set\n");
			break;

		case 4:
			printf("--verbose set\n");
			break;

		case 5:
			printf("--version set\n");
			break;

		case '?':
			printf("unknow\n");
			break;

		default:
			fprintf(stderr, "fault: %c\n", ret);
			return 1;
		}
	}
	printf("-------------------------------\n");
	printf("optarg = %s\n", optarg);
	printf("optind = %d\n", optind);
	printf("opterr = %d\n", opterr);
	printf("optopt = %d\n", optopt);
	printf("optopt = %c\n", optopt);
	if (optind < argc) {
		printf("non-option elements: ");
		while (optind < argc)
			printf("name argument = %s\n", argv[optind++]);
		printf("\n");
	}
	return 0;
}
