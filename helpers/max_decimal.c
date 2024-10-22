#include "../s21_decimal.h"

s21_decimal max_decimal(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  return result;
}