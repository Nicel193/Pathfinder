#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t new_size)
{
    if (ptr == 0)
    {
        return malloc(new_size);
    }

    // size_t cur_size = malloc_size(ptr);
    size_t cur_size = 0;

    if (new_size <= cur_size)
    {
        return ptr;
    }

    void *new_ptr = malloc(new_size);
    mx_memcpy(new_ptr, ptr, cur_size);
    free(ptr);
    return new_ptr;
}

