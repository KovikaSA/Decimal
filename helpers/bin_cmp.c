#include "../s21_decimal.h"

int bin_cmp(s21_decimal d1, s21_decimal d2) {
  int result = 0;
  for (int i = ALL_BITS - 1; i >= 0 && result == 0; i--) {
    result = get_bit(d1, i) - get_bit(d2, i);
  }
  return result;
}