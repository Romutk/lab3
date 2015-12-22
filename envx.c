#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mylibxxx.h"


int main (int argc, char* argv[])
{
char output[256];
char end_path="/environ";
//int result = funxxx();
funxxx(argv[1],end_path, output, sizeof(output));
printf ("%s\n", output);
return 0;
}
