#include "../s21_decimal.h"

int add_handle(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
               int action) {
  int code = 0;
  big_decimal bd1;
  big_decimal bd2;
  big_decimal res;
  int scale1 = get_scale(value_1);
  int scale2 = get_scale(value_2);
  int max_scale = s21_max(scale1, scale2);
  rescaling(value_1, value_2, &bd1, &bd2);
  res = action ? bd_bin_sub(bd1, bd2) : bd_bin_add(bd1, bd2);
  int shift = get_decimal_shift(res);
  int res_scale = max_scale - shift;
  if (res_scale < 0) {
    code = 1;
  } else {
    big_decimal remainder = tobd(Decimal(0));
    big_decimal powten = tobd(ten_pow(shift));
    res = bd_bin_div(res, powten, &remainder);
    set_scale(&remainder.decimals[0], shift);
    res.decimals[0] = round_banking(res.decimals[0], remainder.decimals[0]);
    set_scale(&res.decimals[0], res_scale);
    if (!is_correct(res.decimals[0])) {
      code = 1;
    } else {
      *result = res.decimals[0];
    }
  }
  return code;
}