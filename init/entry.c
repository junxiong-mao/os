#include "console.h"
#include "string.h"


int kern_entry()
{
  console_clear();
  console_write_color("Hello, OS kernel!\n", rc_black, rc_light_red);
  console_write_hex(0, rc_black, rc_light_red);
  console_putc_color('\n', rc_black, rc_white);
  console_write_hex(23, rc_black, rc_light_red);
  console_putc_color('\n', rc_black, rc_white);
  console_write_dec(12345, rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  console_write_dec(0, rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  console_write_dec(0xffffffff, rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  
  console_write_dec(strlen(""), rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  console_write_dec(strlen("12345"), rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  console_write_dec(strlen("aabceeee"), rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  char a[100];
  char *b = "aahfie f eios vj fsjio fe ";
  console_write(strcpy(a, b));
  console_putc_color('\n', rc_black, rc_white);
  memset(a, 'c', 99);
  console_write(a);
  console_putc_color('\n', rc_black, rc_white);
  console_write_dec(strcmp("hellow", "hello"), rc_black, rc_light_white);
  console_putc_color('\n', rc_black, rc_white);
  char *c = "hello";
  char *d = "";
  console_write(strcat(c, d));
  return 0;
}
