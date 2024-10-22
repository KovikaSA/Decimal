#include "../s21_decimal.h"

big_decimal tobd(s21_decimal value) {
  big_decimal result;
  result.decimals[0] = value;
  result.decimals[1] = Decimal(0);
  return result;
}