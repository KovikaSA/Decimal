#include "../s21_decimal.h"

s21_decimal bshift(s21_decimal value, int dir, int amount) {
  s21_decimal result = value;
  for (int count = 0; count < amount; count++) {
    int carry = 0;
    for (int i = 0; i < 4; i++) {
      int j = dir ? i + 1 : 3 - i;
      int temp = get_bit(result, INT_SIZE * j - dir);
      if (dir) {
        result.bits[i] <<= 1;
        if (carry) result = set_bit(result, INT_SIZE * i);
      } else {
        unsigned int bits = result.bits[j];
        result.bits[j] = bits >> 1;
        if (carry) result = set_bit(result, INT_SIZE * (j + 1) - 1);
      }
      carry = temp;
    }
  }
  return result;
}