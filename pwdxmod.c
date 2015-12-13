#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (int argc, char *argv[]) {
	char buf[1024];
	char *b;
	int a;

	sprintf(b,"proc/%s/cwd",argv[1]);
	a = readlink(b,buf,PATH_MAX);
	buf[a]=0;
	printf ("%s:%s\n",argv[1],buf);
	return 0;
}

