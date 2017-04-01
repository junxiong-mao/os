#include "common.h"


inline void outb(uint16_t port, uint8_t value) {
  __asm__ volatile ("outb %0, %1\n\t" : : "a" (value), "dN" (port));
}

inline uint8_t inb(uint16_t port) {
  uint8_t value;
  __asm__ volatile ("inb %1, %0\n\t" : "=a" (value) : "dN" (port));
  return value;
}

inline uint16_t inw(uint16_t port) {
  uint16_t value;
  __asm__ volatile ("inw %1, %0\n\t" : "=a" (value) : "dN" (port));
  return value;
}
