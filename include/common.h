#include "types.h"
#ifndef COMMON_H
#define COMMON_H

#include "types.h"

inline void outb(uint16_t port, uint8_t value);

inline uint8_t inb(uint16_t port);

inline uint16_t inw(uint16_t port);


#endif
