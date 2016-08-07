#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "circbuf.h"

#define malloc_s malloc

// --- Circbuf data structure ----

/** Offset in void* buffer */
#define PV_OFFS(pvBuf, elem_size, index) ((uint8_t*)(pvBuf) + ((elem_size)*(index)))


// Instance structure
struct circbuf_struct {
	void *buf;
	size_t elem_size;
	size_t cap;
	size_t lr; // last read pos
	size_t nw; // next write pos
};


/**
 * @brief Write data to a CircBuf slot
 * @param cb     : circbuf
 * @param index  : slot index
 * @param source : data source
 */
static void write_buffer(CircBuf *cb, size_t index, const void *source)
{
	memcpy(PV_OFFS(cb->buf, cb->elem_size, index), source, cb->elem_size);
}


/**
 * @brief Copy data from a CircBuf slot to a buffer
 * @param cb     : circbuf
 * @param index  : slot index
 * @param dest   : destination buffer
 */
static void read_buffer(const CircBuf *cb, size_t index, void *dest)
{
	memcpy(dest, PV_OFFS(cb->buf, cb->elem_size, index), cb->elem_size);
}


/** Create a cbuf */
CircBuf *cbuf_create(size_t capacity, size_t elem_size)
{
	// add one, because one is always unused.
	capacity++;

	// Allocate the structure
	CircBuf *cb = malloc_s(sizeof(CircBuf));

	// allocate the buffer
	cb->buf = malloc_s(capacity * elem_size);

	// set capacity, clear state
	cb->elem_size = elem_size;
	cb->cap = capacity;
	cbuf_clear(cb);

	return cb;
}


/** Release cbuf memory */
void cbuf_destroy(CircBuf *cb)
{
	if (cb != NULL) {
		if (cb->buf != NULL) {
			free(cb->buf);
		}

		free(cb);
	}
}


/** Check if cbuf is full */
bool cbuf_full(const CircBuf *cb)
{
	if (cb == NULL) return false;

	return (cb->lr == cb->nw);
}


/** Check if cbuf is empty */
bool cbuf_empty(const CircBuf *cb)
{
	if (cb == NULL) return true;

	return ((cb->lr + 1) % cb->cap) == cb->nw;
}


/** Write a byte to the buffer, if space left */
bool cbuf_append(CircBuf *cb, const void *source)
{
	if (cb == NULL) return false;
	if (source == NULL) return false;
	if (cbuf_full(cb)) return false;

	write_buffer(cb, cb->nw, source);

	// increment
	cb->nw++;
	if (cb->nw == cb->cap) cb->nw = 0;

	return true;
}


/** Push value to the end, like a stack. */
bool cbuf_push(CircBuf *cb, const void *source)
{
	if (cb == NULL) return false;
	if (source == NULL) return false;
	if (cbuf_full(cb)) return false;

	write_buffer(cb, cb->lr, source);

	// move lr back
	if (cb->lr == 0) {
		cb->lr = cb->cap - 1; // wrap to the end
	} else {
		cb->lr--;
	}

	return true;
}


/** Read one byte, if not empty. */
bool cbuf_pop(CircBuf *cb, void *dest)
{
	if (cb == NULL || dest == NULL) return false;
	if (cbuf_empty(cb)) return false;

	// increment
	cb->lr++;
	if (cb->lr == cb->cap) cb->lr = 0;

	read_buffer(cb, cb->lr, dest);

	return true;
}


/** Clear a cbuf */
void cbuf_clear(CircBuf *cb)
{
	if (cb == NULL) return;

	cb->lr = cb->cap - 1;
	cb->nw = 0;
}
