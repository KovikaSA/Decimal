#include "../s21_decimal.h"

int get_exp(char *str) {
  int result = 0;
  char *ptr = str;
  for (; *ptr && *ptr != 'E';) ptr++;
  if (*ptr == 'E') result = strtol(ptr + 1, NULL, 10);
  return result;
}