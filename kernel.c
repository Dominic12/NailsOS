#include "kernel.h"
#include "utils/io/print.c"
#include "utils/io/keyboard.c"
#include "nails/boot/printf.c"
#include "utils/io/sata/sata.c"
#include "pwr/pwr.c"
#include "headers/multiboot.h"
#include "mem/mem.c"

extern char start;
extern char end;

void bootstrap(){
  puts("NailsBoot Early Boot Sequence Init\n");
  puts("Init VGA..\n");
  init_vga(WHITE, BLACK);
  puts("VGA Initiated\n");

}
typedef struct memory_map
 {
   unsigned long size;
   unsigned long base_addr_low;
   unsigned long base_addr_high;
   unsigned long length_low;
   unsigned long length_high;
   unsigned long type;
 } memory_map_t;

void kernel_entry(multiboot_info_t* mbd, unsigned int magic)
{

  memory_map_t* mmap = mbd->mmap_addr;
	

  bootstrap();

  printf("Nails Early Boot Info\n----------------------------------\n");
  printf("Bootloader-Name: %s\n", mbd->boot_loader_name);    
  printf("Mods-Addr: 0x%p\n", mbd->mods_addr);  
  printf("Memory-Map Addr: 0x%p\n", mbd->mmap_addr);
  printf("Memory-Map Lenght: %i\n", mbd->mmap_length);
  printf("Memory-Map Lower: 0x%p\n", mbd->mem_lower);
  printf("Memory-Map Upper: 0x%p\n----------------------------------\n", mbd->mem_upper);


  printf("Init_memory..\n");
  Page* firstPage = mem_init(mbd->mem_lower, mbd->mem_upper);
  printf("Aligned First Page with size: %d\n", firstPage->size);
  printf("Aligned First Page at: 0x%p\n", firstPage);

  Page* mem = request_memory(0x100);
  printf("Aligned Second Page with size: %d\n", mem->size);
  printf("Created memory page at: 0x%p\n", mem);
  
  char password[20];

  printf("Hello World %s\n", "dominic");
  printf("Password: ");
  read_line(password);
  if(strcmp(password, "DEADBEEF")){
    puts("Not correct, halting\n");
    shutdown();
    return;
  }else{
    print_string("Correct\n");
  }
  char first[20];
  char second[20];

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
 