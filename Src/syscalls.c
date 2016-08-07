#include <errno.h>
#include <stdio.h>

register char * stack_ptr asm("sp");

caddr_t _sbrk(int incr)
{
	extern char end __asm("end");
	static char *heap_end;
	char *prev_heap_end;

	if (heap_end == 0)
		heap_end = &end;

	prev_heap_end = heap_end;
	if (heap_end + incr > stack_ptr)
	{
//		write(1, "Heap and stack collision\n", 25);
//		abort();
		errno = ENOMEM;
		return (caddr_t) -1;
	}

	heap_end += incr;

	return (caddr_t) prev_heap_end;
}


// Other systcalls are defined in
// - com/com_fileio.c
// - hw_utils/reset.h
