#include "heap.h"
/* used by HeapNew() (defined in ast.h) to allocate whole objects */
GLOBAL void *HeapAllocate(int number, int size)
{
    return calloc(number, size);
}

GLOBAL void HeapFree(void *ptr)
{
    free(ptr);
}