#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {
	char *buf;
	buf = malloc (128);
	char *a;


	a = readlink("/proc/xxxx/cwd" , buf , 128);
	printf ("%s\n",a);
	return 0;
}

