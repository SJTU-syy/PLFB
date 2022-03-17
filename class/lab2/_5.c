/* ptr1.c */
#include <stdio.h>
#include <stdlib.h> 
int main(int argc, char **argv) {
   int x = 4; 
   int *y = &x;
   printf("y=%x, *y=%x, x=%x, &x=%x\n", y, *y, x, &x); 
   return 0;
}