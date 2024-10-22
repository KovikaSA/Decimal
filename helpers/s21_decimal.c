#include "../s21_decimal.h"

s21_decimal Decimal(int number) {
  s21_decimal result;
  clear(&result);
  result.bits[0] = number;
  return result;
}