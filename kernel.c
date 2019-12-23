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

 typedef struct  {
    char signature[4]; // "PCMP"
    uint16_t length;
    uint8_t mp_specification_revision;
    uint8_t checksum; // Again, the byte should be all bytes in the table add up to 0
    char oem_id[8];
    char product_id[12];
    uint32_t oem_table;
    uint16_t oem_table_size;
    uint16_t entry_count; // This value represents how many entries are following this table
    uint32_t lapic_address; // This is the memory mapped address of the local APICs 
    uint16_t extended_table_length;
    uint8_t extended_table_checksum;
    uint8_t reserved;
} mp_configuration_table;



int get_pixel(int y, int x, int pitch, int bpp, unsigned* framebuffer){
  return (y * pitch + (x * (bpp/8)) + framebuffer);
}

void paint(unsigned* framebuffer, int width, int height, int pitch, int bpp){
  printf("Painting.\n");
    for(int y = 0; y < width; ++y)
    {
      for(int x = 0; x < height; ++x)
      {
        int pixel = get_pixel(y, x, pitch, bpp, framebuffer);
        framebuffer[pixel] = 0xFFAAAA00; //yellow color
      }
    }
}
void kernel_entry(multiboot_info_t* mbd, unsigned int magic)
{

  memory_map_t* mmap = mbd->mmap_addr;
  mp_configuration_table* table = (mbd->config_table);
  bootstrap();

  printf("Nails Early Boot Info\n----------------------------------\n");
  printf("Bootloader-Name: %s\n", mbd->boot_loader_name);    
  printf("Mods-Addr: 0x%p\n", mbd->mods_addr);  
  printf("Memory-Map Addr: 0x%p\n", mbd->mmap_addr);
  printf("Memory-Map Lenght: %i\n", mbd->mmap_length);
  printf("Memory-Map Lower: 0x%p\n", mbd->mem_lower);
  printf("Memory-Map Upper: 0x%p\n", mbd->mem_upper);

  printf("Framebuffer At: 0x%p\n", mbd->framebuffer_addr);
  printf("Framebuffer BPP: %i\n", mbd->framebuffer_bpp);
  printf("Framebuffer Width: %i\n", mbd->framebuffer_width);
  printf("Framebuffer Height: %i\n", mbd->framebuffer_height);
  printf("Framebuffer Pitch: %s\n", mbd->framebuffer_pitch);
  printf("Signature: %c\n", table->signature[0]);


  printf("----------------------------------\n");

  paint(mbd->framebuffer_addr, mbd->framebuffer_width, mbd->framebuffer_height, mbd->framebuffer_pitch, mbd->framebuffer_bpp);
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
 