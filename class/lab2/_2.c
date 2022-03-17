/* this is a C-style comment 
 * You generally want to palce
 * all file includes at start of file
 * */
#include <stdio.h>

int main (int argc, char **argv)
{
   // this is a C++-style comment
   // printf prototype in stdio.h
   printf("We have %d arguments\n", argc);
   printf("The first argument, argv[0] = %s\n", argv[0]);
   printf("The other arguments are %s, %s\n", argv[1], argv[2]);
   return 0;
}