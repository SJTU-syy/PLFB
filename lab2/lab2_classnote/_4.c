/* all_argv.c */
#include <stdio.h> 
#include <stdlib.h> 
#define mymult(a, b) (a)*(b)

int main(int argc, char **argv ) 
{
   int i=0; 
   printf("there are %d arguments\n", argc); 
   printf("Program name: %s\n", argv[0]); 
   
   for(i = 1; i< argc; i++) {
      printf("argv[%d]=%s\n", i, argv[i]); 
   }
   
   return 0;
}