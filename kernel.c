#include "kernel.h"
#include "utils/io/print.c"
#include "utils/io/keyboard.c"
#include "heap/malloc/malloc.c"
#include "nails/boot/printf.c"
#include "utils/io/sata/sata.c"

void kernel_entry()
{
  init_vga(WHITE, BLACK);
  void* heap = init_heap();
  printf("Heap initialized at 0x%p\n", heap);
  printf("Welcome to NailsOS 1.0\n");
  printf("Hello World %s\n", "dominic");

  struct DEVICE *device;
  device->base = 0x1F0;
  device->dev_ctl = 0x3F6;

  int dev = detect_devtype(4, device);
  
  switch (dev)
  {
  case 0:
    printf("Detected ATADEV_PATAPI\n");
    break;
  case 1:
    printf("Detected ATADEV_SATAPI\n");
    break;
  case 2:
    printf("Detected ATADEV_PATA\n");
    break;
  case 3:
    printf("Detected ATADEV_SATA\n");
    break;
  case 4:
    printf("Detected ATADEV_UNKOWN\n");
    break;
  default:
    printf("Detected WTF???\n");
    break;
  }

  printf("Password: ");
  char first[20];
  char second[20];

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
 