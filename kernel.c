#include "kernel.h"
#include "utils/io/print.c"
#include "utils/io/keyboard.c"
#include "heap/malloc/malloc.c"

void kernel_entry()
{
  init_vga(WHITE, BLACK);
  void* heap = init_heap();
  print_string("Heap initialized at 0x");
  print_int(heap);
  print_string("\n");
  print_string("Welcome to NailsOS 1.0\n");
  print_string("Password: ");
  char* test = read_line();
  print_string("Confirm: ");
  char* second = read_line();
  
  print_string(test);
  if(_strcmp(test, second)){
    print_string("Not correct");
  }else{
    print_string("Correct");
  }

}
 