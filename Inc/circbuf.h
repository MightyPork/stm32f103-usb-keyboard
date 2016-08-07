/**
 * @file circbuf.h
 * @author Ondřej Hruška, 2016
 *
 * Circular buffer / queue / stack.
 * Slots are pre-allocated, values are copied into the buffer.
 *
 * The buffer may be used as a stack, event queue or a simple buffer.
 *
 * -------------------------------------
 *
 *         NW        LR
 * append -> [][][][] -> pop
 *                    <- push
 *
 * NW - next write pointer (stack base)
 * LR - last read position (stack top)
 *
 * -------------------------------------
 *
 * MIT license
 */

#ifndef F103_USB_CIRCBUF_H
#define F103_USB_CIRCBUF_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct circbuf_struct CircBuf;


/**
 * @brief Initialize a circular buffer. The buffer is malloc'd.
 * @param capacity  : buffer capacity
 * @param elem_size : size of one element
 * @return pointer to the buffer instance
 */
CircBuf *cbuf_create(size_t capacity, size_t elem_size);


/**
 * @brief Destroy a buffer, freeing used memory.
 *
 * @attention
 * If the buffer items have malloc'd members, you have
 * to free them manually to avoid a memory leak.
 *
 * @param cb : buffer
 */
void cbuf_destroy(CircBuf *cb);


/** Test for full buffer */
bool cbuf_full(const CircBuf *cb);


/** Test for empty buffer */
bool cbuf_empty(const CircBuf *cb);


/**
 * @brief Append a value to the buffer (FIFO)
 * @param cb     : buffer
 * @param source : pointer to a value (will be copied)
 * @return success
 */
bool cbuf_append(CircBuf *cb, const void *source);


/**
 * @brief Push a value into the circbuf (LIFO).
 *
 * @param cb     : buffer
 * @param source : pointer to a value (will be copied)
 * @return success
 */
bool cbuf_push(CircBuf *cb, const void *source);


/**
 * @brief Read a value from the buffer, return success.
 *
 * @param cb   : buffer
 * @param dest : read destionation. If NULL, value is discarded.
 * @return success
 */
bool cbuf_pop(CircBuf *cb, void *dest);


/** @brief Remove all data from buffer */
void cbuf_clear(CircBuf *cb);

#endif // F103_USB_CIRCBUF_H
