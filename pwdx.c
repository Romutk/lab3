#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int check_pid_argument(char *input)
{
	int skip = 0;
	long pid;
	char *end = NULL;

	pid = strtol(input + skip, &end, 10);

	return 0;
}

int main(int argc, char *argv[])
{
	int ch;
	int retval = 0, i;
	int alloclen = 128;
	char *pathbuf;

	static const struct option longopts[] = {
		{"version", no_argument, 0, 'V'},
		{"help", no_argument, 0, 'h'},
		{NULL, 0, 0, 0}
	};


	while ((ch = getopt_long(argc, argv, "Vh", longopts, NULL)) != -1)
		switch (ch) {
		case 'h':
			usage(stdout);
		default:
			usage(stderr);
		}

	argc -= optind;
	argv += optind;

	if (argc == 0)
		usage(stderr);

	pathbuf = malloc(alloclen);

	for (i = 0; i < argc; i++) {
		char *s;
		ssize_t len, buflen;
		char *buf;
		buflen = 10 + strlen(argv[i]) + 1;
		buf = xmalloc(buflen);

		if (argv[i][0] != '/')
			snprintf(buf, buflen, "/proc/%s/cwd", argv[i]);
		else
			snprintf(buf, buflen, "%s/cwd", argv[i]);

		while ((len = readlink(buf, pathbuf, alloclen)) == alloclen) {
			alloclen *= 2;
			pathbuf = realloc(pathbuf, alloclen);
		}
		free(buf);

			pathbuf[len] = 0;
			s = pathbuf;
	free(pathbuf);
	return 0;
