struct FastChunk{
    uint32 size;
    void* fd;
    void* bk;
    void* fd_next_size;
    void* bk_next_size;
    uint32 prev_size;
};

#define HEAP_START 0x9c4b008
#define HEAP_END 0x9C50008