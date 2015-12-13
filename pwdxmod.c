#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main (int argc, char *argv[]) {
//	char buf[1024];
	char *b;
	int a;
	int c;

for (c=1;c<argc;c++) {
	buflen = 10 + strlen(argv[c])+1;
	buf= xmalloc(buflen);
//	sprintf(b,"/proc/%s/cwd",argv[c]);
	sprintf (buf,buflen,"/proc/%S/cwd",argv[c]);


	a = readlink(b,buf,PATH_MAX);
	buf[a]=0;
	printf ("%s:%s\n",argv[c],buf);
}
}

