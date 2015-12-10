
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	int ch;
	int retval = 0, i;
	int alloclen = 128;
	char *pathbuf;

m	while ((ch = getopt_long(argc, argv, "Vh", longopts, NULL)) != -1)
		switch (ch) {
		case 'V':
			printf(PROCPS_NG_VERSION);
			return EXIT_SUCCESS;
		case 'h':
			usage(stdout);
		default:
			usage(stderr);
		}

	argc -= optind;
	argv += optind;

	pathbuf = malloc(alloclen);

	for (i = 0; i < argc; i++) {
		char *s;
		ssize_t len, buflen;
		/* Constant 10 is the length of strings "/proc/" + "/cwd" + 1 */
		char *buf;
		buflen = 10 + strlen(argv[i]) + 1;
		buf = xmalloc(buflen);

		if (argv[i][0] != '/')
			snprintf(buf, buflen, "/proc/%s/cwd", argv[i]);
		else
			snprintf(buf, buflen, "%s/cwd", argv[i]);

		/*
		 * buf contains /proc/NNNN/cwd symlink name
		 * on entry, the target of that symlink on return
		 */
		while ((len = readlink(buf, pathbuf, alloclen)) == alloclen) {
			alloclen *= 2;
			pathbuf = realloc(pathbuf, alloclen);
		}
		free(buf);

			pathbuf[len] = 0;
			s = pathbuf;
		
		printf("%s: %s\n", argv[i], s);
	}
	free(pathbuf);
	return retval;
}
