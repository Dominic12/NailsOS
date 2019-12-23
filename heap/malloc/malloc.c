#include "../heap.h"
#include "../../types.h"


void *init_heap(){
    struct FastChunk *entry_chunk;
    entry_chunk = (struct FastChunk*)HEAP_START;
    entry_chunk->size = 0;
    entry_chunk->prev_size = 0;
    entry_chunk->bk = entry_chunk;
    entry_chunk->fd = 0xffff;
    return entry_chunk;
}
void* nextFree(struct FastChunk *chunk){
    if(chunk->fd = 0xffff){
        return chunk->size + &chunk;
    }
    return nextFree(chunk);
}
void* malloc(size_t size){
    struct FastChunk *entry_chunk;
    entry_chunk = (struct FastChunk*)HEAP_START;
    struct FastChunk *fd_chunk;
    fd_chunk = (struct FastChunk*)nextFree(entry_chunk);
    
    //initialize nextChunk with size and return it
    fd_chunk->size = size;
    return fd_chunk->fd_next_size;
}