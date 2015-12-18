#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

	int main(int argc, char *argv[])
	int i;
	char c[1];
	char *path[];
	int alloclen = 128;

argc -= optind;
argv += optind;


for (i = 0; i < argc; i++) {
ssize_t  buflen;
char *buf;
buflen = 15 + strlen(argv[i]) + 1;
path = malloc(buflen);

snprintf(path, buflen, "/proc/%s/environ", argv[i]);


	i=open(path,O_RDONLY);
	read(i,c,1);
	if (c!=|);
	putc(c);
else 
putc('/n')

