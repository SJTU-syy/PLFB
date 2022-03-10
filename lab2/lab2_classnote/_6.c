/* ptr2.c */
   #include <stdio.h>
   
   int main(int argc, char **argv ) {
      int i=0;
      int x[5], *ptr;
      for (i = 0; i < 5; i ++) {
         x[i] = i + 1;
      } 
       
      ptr = &x[0];
      printf("ptr=%p\n", ptr); 
   
      for (i = 0; i < 5; i ++) {
         printf("the # %d element: x[%d] = %d\n", i, i, x[i]);
      }
      
      return 0;
   }