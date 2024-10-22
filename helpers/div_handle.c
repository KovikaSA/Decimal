#include "../s21_decimal.h"

int div_handle(big_decimal quotient, big_decimal divisor, big_decimal rem,
               s21_decimal *res) {
  int code = 0;
  int scale1 = calc_fractional(&quotient, divisor, &rem);
  big_decimal tmp_res = tobd(Decimal(0));
  int scale2 = calc_fractional(&tmp_res, divisor, &rem);
  set_scale(&tmp_res.decimals[0], scale2);
  quotient.decimals[0] =
      round_banking(quotient.decimals[0], tmp_res.decimals[0]);
  set_scale(&quotient.decimals[0], scale1);
  *res = quotient.decimals[0];
  return code;
}