
#include "../../kernel.h"
#include "../char.c"
#include "../string.c"
#include "../../types.h"
#include "port.c"
void wait_for_io(uint32 timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}

void sleep(uint32 timer_count)
{
  wait_for_io(timer_count);
}



char get_input_keycode()
{
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

char* read_line(char* buf){
    char c = 0;
    while(c = get_input_keycode(), c != KEY_ENTER){
        char a_char = get_ascii_char(c);
        char currChar[2];
        currChar[1] = '\0';
        currChar[0] = a_char;
        buf = strncat(buf, currChar, (sizeof(buf) / sizeof(char*)) + 2);
        print_char(a_char);
        sleep(0x04FFFFFF);
    }
    print_new_line();
        sleep(0x02FFFFFF);

    return buf;
}
