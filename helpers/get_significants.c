#include "../s21_decimal.h"

int get_significants(s21_decimal value) {
  int result = -1;
  for (int i = ALL_BITS - 1; i >= 0 && result == -1; i--) {
    if (get_bit(value, i)) result = i;
  }
  return result;
}