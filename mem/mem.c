#include "mem.h"


/*
    Dump, yet unefficient way of managing memory. Certainly needs more attention in the future.
*/
void* lower_mem;
void* upper_mem;
Page* top_page; // Keep track of the Top page, (Performance)
int freeMemory = 0;
Page* create_page(void* addr, size_t size);
void *memset(void *s, int c, size_t n);

Page* mem_init(void* lower, void* upper){
    lower_mem = lower;
    upper_mem = upper;
    return create_page(lower, (size_t)0x50);
}


Page* create_page(void* addr, size_t size){
    printf("Creating page at: 0x%p\n", addr);
    Page *page = (Page*)addr;
    page->size = size;
    memset(page->rw_data, 0, sizeof(page->rw_data)); //Clear out arbitary data
    top_page = page;
    return page;
}
Page* request_memory(size_t size){
    printf("Memory requested and able to serve\n");
    return create_page(top_page + top_page->size, size);
}



void *memset(void *s, int c, size_t n)
{
    unsigned char* p=s;
    while(n--)
        *p++ = (unsigned char)c;
    return s;
}