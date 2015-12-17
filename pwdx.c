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
char ch;
int retval = 0, i;
int alloclen = 128;
char *pathbuf;

argc -= optind;
argv += optind;

pathbuf = malloc(alloclen);

for (i = 0; i < argc; i++) {
ssize_t len, buflen;
char *buf;
buflen = 10 + strlen(argv[i]) + 1;
buf = malloc(buflen);

snprintf(buf, buflen, "/proc/%s/cwd", argv[i]);

while ((len = readlink(buf, pathbuf, alloclen)) == alloclen) {
alloclen *= 2;
pathbuf = realloc(pathbuf, alloclen);
}
free(buf);

pathbuf[len] = 0;

printf("%s: %s\n", argv[i], pathbuf);
}
free(pathbuf);
return retval;
}
