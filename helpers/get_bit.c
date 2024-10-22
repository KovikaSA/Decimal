#include "../s21_decimal.h"

int get_bit(s21_decimal value, int index) {
  return (value.bits[index / INT_SIZE] & (1 << (index % INT_SIZE))) != 0;
}