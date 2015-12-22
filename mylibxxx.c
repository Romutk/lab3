#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <mylibxxx.h>


char * funxxx (char *pid, char end_path, char *output, size_t limit) {
	char str[80];

// concatinate structure
	strcpy(str, "/proc/");
	strcat(str, pid);
	strcat(str, end_path);


	printf("%s\n",str);

// read from file
	char ch;
	FILE *fp;
	fp = fopen(str,"r");

	int count = 0;
	while( ( ch = fgetc(fp) ) != EOF ) {
		if(count == limit)
			continue;
		output[count] = ch;
		count++;
	}

	fclose(fp);
	return output;
}
