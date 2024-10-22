#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  if (!dst) {
    status = 1;
  } else if (!is_correct(src)) {
    status = 1;
    *dst = 0.0;
  } else if (s21_is_equal(src, Decimal(0))) {
    *dst = 0.0;
    if (get_sign(src)) *dst = -0.0;
  } else {
    double tmp = 0.0;
    for (int i = 0; i < BASE_SIZE; i++) {
      if (get_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }
    tmp /= pow(10, get_scale(src));
    if (get_sign(src)) tmp *= -1.0;
    *dst = (float)tmp;
  }
  return status;
}