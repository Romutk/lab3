#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (int argc, char *argv[]) {
	char buf[1024];
	char *b;
	int a;
	int c;

for (c=1; c<argc;,c++) {
	sprintf(b,"proc/%s/cwd",argv[c]);
	a = readlink(b,buf,PATH_MAX);
	buf[a]=0;
	printf ("%s:%s\n",argv[c],buf);
}
	return 0;
}

