#include "../s21_decimal.h"

s21_decimal bin_add(s21_decimal d1, s21_decimal d2) {
  s21_decimal res = d1;
  s21_decimal tmp = d2;
  while (!is_null(tmp)) {
    s21_decimal of = decimal_logic(res, tmp, _and);
    of = bshift(of, LEFT, 1);
    res = decimal_logic(res, tmp, _xor);
    tmp = of;
  }
  return res;
}