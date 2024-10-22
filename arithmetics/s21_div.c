#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  if (result && s21_is_equal(value_2, Decimal(0))) {
    status = 3;
  } else if (result && is_correct(value_1) && is_correct(value_2)) {
    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    big_decimal bd1;
    big_decimal bd2;
    rescaling(value_1, value_2, &bd1, &bd2);
    big_decimal rem = tobd(Decimal(0));
    big_decimal res = bd_bin_div(bd1, bd2, &rem);
    if (res.decimals[0].bits[3] != 0 || !is_null(res.decimals[1])) {
      status = 1 + (sign1 != sign2);
    } else {
      status = div_handle(res, bd2, rem, result);
      if (sign1 != sign2) set_sign(result, 1);
      if (get_sign(*result) == 1 && status == 1) status = 2;
      if (status == 0 && s21_is_not_equal(value_1, Decimal(0)) &&
          s21_is_equal(*result, Decimal(0))) {
        status = 2;
      }
    }
  }
  return status;
}