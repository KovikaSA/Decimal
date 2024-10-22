#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  if (result && is_correct(value_1) && is_correct(value_2)) {
    s21_decimal res = Decimal(0);
    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    if (sign1 == 0 && sign2 == 0) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        status = add_handle(value_1, value_2, &res, 1);
      } else {
        status = add_handle(value_2, value_1, &res, 1);
        s21_negate(res, &res);
      }
    } else if (sign1 == 0 && sign2 == 1) {
      status = s21_add(value_1, decimal_abs(value_2), &res);
    } else if (sign1 == 1 && sign2 == 0) {
      status = s21_add(decimal_abs(value_1), value_2, &res);
      s21_negate(res, &res);
    } else if (sign1 == 1 && sign2 == 1) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        status =
            add_handle(decimal_abs(value_2), decimal_abs(value_1), &res, 1);
      } else {
        status =
            add_handle(decimal_abs(value_1), decimal_abs(value_2), &res, 1);
        s21_negate(res, &res);
      }
    }
    if (get_sign(res) == 1 && status == 1) status = 2;
    *result = res;
  }
  return status;
}