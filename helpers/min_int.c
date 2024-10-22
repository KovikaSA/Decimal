#include "../s21_decimal.h"

s21_decimal min_int(void) {
  s21_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};
  return result;
}