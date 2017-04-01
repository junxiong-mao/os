#include "common.h"
#include "console.h"

static uint16_t *video_memory = (uint16_t *)0xB8000;
static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

static void move_cursor() {
  uint16_t cursorLocation = 80 * cursor_y + cursor_x;
  outb(0x3D4, 14);
  outb(0x3D5, cursorLocation >> 8);
  outb(0x3D4, 15);
  outb(0x3D5, cursorLocation);
}

void console_clear() {
  uint8_t attribute = (0 << 4) | (15 & 0x0F);
  uint16_t blank = 0x20 | (attribute << 8);
  int i = 0;
  for (i = 0; i < 80 * 25; i++) {
    video_memory[i] = blank;
  }

  cursor_x = 0;
  cursor_y = 0;
  move_cursor();
}

static void scroll() {
  uint8_t attribute = (0 << 4) | (15 & 0x0F);
  uint16_t blank = 0x20 | (attribute << 8);
  if (cursor_y >= 25) {
    int i = 0;
    for (i = 0; i < 24 * 80; i++) {
      video_memory[i] = video_memory[i + 80];
    }

    for (i = 24 * 80; i < 25 * 80; i++) {
      video_memory[i] = blank;
    }
    cursor_y = 24;
  }
}

void console_putc_color(char c, real_color_t back, real_color_t fore) {
  uint8_t back_color = (uint8_t) back;
  uint8_t fore_color = (uint8_t) fore;
  uint8_t attribute_byte = (back_color << 4) | fore_color;
  uint16_t attribute = attribute_byte << 8;

  if (c == 0x08 && cursor_x) {
    cursor_x--;
  } else if (c == 0x09) {
    cursor_x = (cursor_x + 8) & ~(8 - 1);
  } else if (c == '\r') {
    cursor_x = 0;
  } else if (c == '\n') {
    cursor_x = 0;
    cursor_y++;
  } else if (c >= ' ') {
    video_memory[cursor_y * 80 + cursor_x] = c | attribute;
    cursor_x++;
  }

  if (cursor_x >= 80) {
    cursor_x = 0;
    cursor_y++;
  }

  scroll();
  move_cursor();
}

void console_write(char *str) {
  while (*str) {
    console_putc_color(*str, rc_black, rc_white);
    str++;
  }
}

void console_write_color(char *str, real_color_t back, real_color_t front) {
  while (*str) {
    console_putc_color(*str, back, front);
    str++;
  }
}

void console_write_hex(uint32_t n, real_color_t back, real_color_t front) {
  char value[11];
  value[10] = '\0';
  int i = 9;
  do {
    int temp = n % 16;
    if (temp <= 9) {
      value[i] = '0' + temp;
    } else {
      value[i] = 'A' + temp - 10;
    }
    i--;
  } while ((n /= 16) && i >= 2);
  value[i] = 'X';
  value[i - 1] = '0';
  console_write_color(value + i - 1, back, front);
}

void console_write_dec(uint32_t n, real_color_t back, real_color_t front) {
  char value[11];
  value[10] = '\0';
  int i = 9;
  do {
    int temp = n % 10;
    value[i] = '0' + temp;
    i--;
  } while ((n /= 10) && i >= 0);
  console_write_color(value + i + 1, back, front);
}











