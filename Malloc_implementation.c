//1. Naive implementation with no reuse of block

#define ALIGNMENT 8 // must be a power of 2
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))
#define SIZE_T_SIZE (ALIGN(sizeof(size_t))) // header size

void* malloc(size_t size)
{
    size_t block_size = ALIGN(size + SIZE_T_SIZE)
    
    size_t *header = sbrk(block_size);

    *header = block_size |1 ; //set bit to 1 to indicate block is used

    return (char*)header - SIZE_T_SIZE;
}

void free(void *ptr)
{
    size_t *header = pts - SIZE_T_SIZE;
    *header = *header & ~1L; // unmark allocated bit
}

//2. With re-use
void *find_fit(size_t size) {
 size_t *header = heap_start();
 while (header < heap_end()) {
 if (!(*header & 1) && *header >= size)
 return header;
 header = (char *)header + (*header & ~1L);
 }
 return NULL;
}
