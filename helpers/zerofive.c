#include "../s21_decimal.h"

s21_decimal zerofive(void) {
  s21_decimal result = {{0x5, 0x0, 0x0, 0x10000}};
  return result;
}