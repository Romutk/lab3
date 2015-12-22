#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

char * funxxx (char* spid,char*end_path,char * target_path,size_t limit)
{
 char link_path[256]="/proc/";
 int len;
 
 strcat(strcat(link_path,spid),end_path);
    
  /* Attempt to read the target of the symbolic link. */
 len = readlink (link_path, target_path, limit);
 printf("link_path='%s',target_path='%s',len=%i\n",link_path,target_path,len);
   /* NUL-terminate the target path. */
  target_path[len] = '\0';
    
  return target_path;
}
