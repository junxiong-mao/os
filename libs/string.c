#include "string.h"

inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len) {
  for (; len != 0; len--) {
    *dest++ = *src++;
  }
}

inline void memset(void *dest, uint8_t val, uint32_t len) {
  uint8_t *dst = (uint8_t *)dest;
  for (; len != 0; len--) {
    *dst++ = val;
  }
}

inline void bzero(void *dest, uint32_t len) {
  memset(dest, 0, len);
}

inline int strlen(const char *src) {
  int len = 0;
  while (*src++) {
    len++;
  }
  return len;
}

inline int strcmp(const char *str1, const char *str2) {
  while (*str1 && str2) {
    char temp = *str1 - *str2;
    if (temp) {
      return temp;
    }
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

inline char *strcpy(char *dest, const char *src) {
  memcpy((uint8_t *)dest, (uint8_t *)src, strlen(src) + 1);
  return dest;
}

inline char *strcat(char *dest, const char *src) {
  char *head = dest;
  while (*dest) {
    dest++;
  }
  dest = strcpy(dest, src); 
  return head;
}
