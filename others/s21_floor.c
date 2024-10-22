#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int code = 1;
  if (result && is_correct(value)) {
    code = 0;
    int sign = get_sign(value);
    s21_decimal fraction;
    s21_decimal unsigned_truncated;
    s21_decimal value_unsigned = decimal_abs(value);
    s21_truncate(value_unsigned, &unsigned_truncated);
    s21_sub(value_unsigned, unsigned_truncated, &fraction);
    if (sign == 1 && s21_is_greater(fraction, Decimal(0))) {
      s21_add(unsigned_truncated, Decimal(1), &unsigned_truncated);
    }
    *result = unsigned_truncated;
    set_sign(result, sign);
  }
  return code;
}