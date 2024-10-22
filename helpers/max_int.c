#include "../s21_decimal.h"

s21_decimal max_int(void) {
  s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  return result;
}
