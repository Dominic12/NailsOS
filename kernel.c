#include "kernel.h"
#include "utils/io/print.c"
#include "utils/io/keyboard.c"


void kernel_entry()
{
  init_vga(WHITE, BLACK);

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
 