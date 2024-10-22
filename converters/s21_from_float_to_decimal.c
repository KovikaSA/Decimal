#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  if (!dst) {
    status = 1;
  } else if (src == 0.0) {
    *dst = Decimal(0);
  } else if (isinf(src) || isnan(src) || fabsf(src) > MAX_FLOAT ||
             fabsf(src) < MIN_FLOAT) {
    status = 1;
  } else {
    char float_string[16];
    sprintf(float_string, "%.6E", fabsf(src));
    *dst = float_string_to_decimal(float_string);
  }
  if (dst) set_sign(dst, signbit(src) != 0);
  return status;
}