#include "../s21_decimal.h"

int bd_bin_cmp(big_decimal d1, big_decimal d2) {
  int compare = bin_cmp(d1.decimals[1], d2.decimals[1]);
  if (compare == 0) {
    compare = bin_cmp(d1.decimals[0], d2.decimals[0]);
  }
  return compare;
}