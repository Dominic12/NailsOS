
#include "../../kernel.h"
#include "../char.c"
#include "../string.c"


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

uint8 inb(uint16 port)
{
  uint8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outb(uint16 port, uint8 data)
{
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
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

char* read_line(){
    int last = 0;
    char c = 0;
    int enterIdx = 0;
    char* buf;
    while(c = get_input_keycode(), c != KEY_ENTER){
        char a_char = get_ascii_char(c);
        buf[last] = a_char;
        ++last;
        enterIdx = last + 1;
        print_char(a_char);
        sleep(0x04FFFFFF);
    }
    buf[enterIdx] = '\0';
    print_new_line();
        sleep(0x02FFFFFF);

    return buf;
}
