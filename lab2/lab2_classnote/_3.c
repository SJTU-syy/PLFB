/* macro.c */
#include <stdio.h> 
#include <stdlib.h> 
#define mymult(a, b) (a)*(b)
#define mymult2(a, b) a*b

int main(int argc, char **argv ) {
   int k1 = mymult(6+3, 4+3); 
   printf ("k1=(6+3)*(4+3)=%d\n", k1); 
   int k2 = mymult2(6+3, 4+3); 
   printf ("k2=(6+3)*(4+3)=%d\n", k2);
   exit(0);
}