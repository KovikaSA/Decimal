#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  if (result && is_correct(value_1) && is_correct(value_2)) {
    s21_decimal res = Decimal(0);
    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    status = mul_handle(decimal_abs(value_1), decimal_abs(value_2), &res);
    if (sign1 != sign2) set_sign(&res, 1);
    if (status == 1 && get_sign(res)) status = 2;
    if (status == 0 && s21_is_not_equal(value_1, Decimal(0)) &&
        s21_is_not_equal(value_2, Decimal(0)) &&
        s21_is_equal(res, Decimal(0))) {
      status = 2;
    }
    *result = res;
  }
  return status;
}