#include "..//s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int status = 0;
  if (!dst) {
    status = 1;
  } else {
    *dst = Decimal(0);
    set_sign(dst, (unsigned int)src >> 31);
    dst->bits[0] = abs(src);
  }
  return status;
}