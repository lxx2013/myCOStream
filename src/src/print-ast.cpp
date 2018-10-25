/*这个文件用于编写 输出抽象语法树 所用的函数*/
#include <ctype.h>
#include "ast.h"
#include <stdio.h>
#include <string.h>

GLOBAL void CharToText(char *array, unsigned char value)
{
  if (value < ' ') {
    static const char *names[32] = {
      "nul","soh","stx","etx","eot","enq","ack","bel",
      "\\b", "\\t", "\\n", "\\v", "ff", "cr", "so", "si",
      "dle","dc1","dc2","dc3","dc4","nak","syn","etb",
      "can","em", "sub","esc","fs", "gs", "rs", "us" };
    sprintf(array, "0x%02x (%s)", value, names[value]);
  } else if (value < 0x7f) {
    sprintf(array, "'%c'", value);
  } else if (value == 0x7f) {
    strcpy(array, "0x7f (del)");
  } else { /* value >= 0x80 */
    sprintf(array, "0x%x", value);
  }
}