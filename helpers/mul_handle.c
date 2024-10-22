#include "../s21_decimal.h"

int mul_handle(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  int scale1 = get_scale(value_1);
  int scale2 = get_scale(value_2);
  clear_service(&value_1);
  clear_service(&value_2);
  big_decimal res = bd_bin_mul(tobd(value_1), value_2);
  int shift = get_decimal_shift(res);
  int res_scale = scale1 + scale2 - shift;
  if (res_scale < 0) {
    code = 1;
  } else {
    big_decimal remainder = tobd(Decimal(0));
    big_decimal powten = tobd(ten_pow(shift));
    res = bd_bin_div(res, powten, &remainder);
    set_scale(&remainder.decimals[0], shift);
    res.decimals[0] = round_banking(res.decimals[0], remainder.decimals[0]);
    set_scale(&res.decimals[0], res_scale);
    *result = res.decimals[0];
  }
  return code;
}