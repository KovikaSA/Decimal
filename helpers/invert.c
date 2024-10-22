#include "../s21_decimal.h"

s21_decimal invert(s21_decimal value) {
  s21_decimal result = Decimal(0);
  for (int i = 0; i < 4; i++) {
    result.bits[i] = ~value.bits[i];
  }
  return result;
}