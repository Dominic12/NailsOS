#include "kernel.h"
#include "utils/io/print.c"
#include "utils/io/keyboard.c"
#include "heap/malloc/malloc.c"
#include "nails/boot/printf.c"
void kernel_entry()
{
  init_vga(WHITE, BLACK);
  void* heap = init_heap();
  printf("Heap initialized at 0x%p\n", heap);
  printf("Welcome to NailsOS 1.0\n");
  printf("Hello World %s\n", "dominic");

  printf("Password: ");
  char first[20];
  char* second[20];

  printf("First is at: 0x%p\n", first);
  printf("Second is at: 0x%p\n", second);
  printf("First: ");
  read_line(first);
  printf("Confirm: ");
  read_line(second);
  
  printf("First is: %s\n", first);
  printf("Second is: %s\n", second);

 

  if(strcmp(first, second)){
    print_string("Not correct");
  }else{
    print_string("Correct");
  }

}
 