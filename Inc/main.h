//
// Created by ondra on 7.8.16.
//

#ifndef F103_USB_MAIN_H_H
#define F103_USB_MAIN_H_H

#include "stm32f1xx_hal.h"
#include "circbuf.h"

extern void dbg(const char* msg);

extern CircBuf *key_cbuf;

#endif //F103_USB_MAIN_H_H
