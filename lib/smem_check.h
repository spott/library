#ifdef MEM_CHECK
#include <stdlib.h>

/* get the line number (__LINE__) and filename (__FILE__) using macros, 
 * then connect them and put them in a hash with the number of bytes allocated
 * then use malloc to aquire A + 20 bytes and return a pointer 10 bytes into the
 * allocation.  I think I can do this by adding 10 to the pointer.  These 20 bytes
 * should have a pattern filled in ("000000" works I think...)
 */ 
#define smalloc(A, N) void *p = (calloc(1,(sizeof(A)*N)+20) + 10); hash_table_add_s(ht, (int)p, (void *)(sizeof(A)*N + 20))

#define sfree(A) free(A); hash_table_find(ht, (int)A, dummy, 1)

#else /* MEM_CHECK */

#define smalloc(A) malloc(A)
#define sfree(A) free(A)
#define srealloc(A) realloc(A)

#endif /* MEM_CHECK */

