#include "../types.h"

void shutdown(){
    print_string("Shutdown");
    	__asm__ __volatile__ ("outw %1, %0" : : "dN" ((uint16_t)0xB004), "a" ((uint16_t)0x2000));
}