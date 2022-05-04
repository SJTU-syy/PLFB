#include <stdio.h>

char *global_string1 = "abc";
char *global_string2 = "Hello World!!!";
const int global_const_int = 0x81;
int global_int = 0x3FF;
int global_uninit_int;

int main()
{
  int stack_int = 0x1F;
  static int stack_uninit_static_int;
  static int stack_inited_static_int = 0x1B;

  char *stack_string1 = "Hello World!!!";
  char *stack_string2 = "Hello";

  printf("sizeof int is %d\n", sizeof(int));

  printf("addr of global_string1 is 0x%x\n \
        addr of global_string2 is 0x%x\n \
        addr of stack_string1 is 0x%x\n \
        addr of stack_string2 is 0x%x\n", global_string1, global_string2, stack_string1, stack_string2);

  printf("addr of global_const_int is 0x%x\n", &global_const_int);
  printf("addr of global_int is 0x%x\n \
        addr of stack_inited_static_int is 0x%x\n", &global_int, &stack_inited_static_int);

  printf("addr of global_uninit_int is 0x%x\n \
        addr of stack_uninit_static_int is 0x%x\n", &global_uninit_int, &stack_uninit_static_int);


  printf("addr of stack_int is 0x%x\n", &stack_int);

  return 0;
}