#include "../s21_decimal.h"

s21_decimal set_bit(s21_decimal value, int index) {
  value.bits[index / INT_SIZE] |= 1 << index % INT_SIZE;
  return value;
}