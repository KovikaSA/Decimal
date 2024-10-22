#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = 0;
  if (!dst) {
    status = 1;
  } else if (!is_correct(src)) {
    status = 1;
    *dst = 0;
  } else {
    *dst = 0;
    s21_decimal truncated = Decimal(0);
    s21_truncate(src, &truncated);
    if (s21_is_less(truncated, min_int())) {
      status = 1;
    } else if (s21_is_greater(truncated, max_int())) {
      status = 1;
    } else {
      *dst = truncated.bits[0];
      if (get_sign(src) == 1 && *dst != INT_MIN) *dst = -*dst;
    }
  }
  return status;
}