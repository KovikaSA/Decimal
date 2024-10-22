#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int code = 1;
  if (result && is_correct(value)) {
    code = 0;
    int sign = get_sign(value);
    s21_decimal fraction;
    s21_decimal unsigned_truncated;
    s21_decimal value_unsigned = decimal_abs(value);
    s21_truncate(value_unsigned, &unsigned_truncated);
    s21_sub(value_unsigned, unsigned_truncated, &fraction);
    s21_decimal half = zerofive();
    if (s21_is_greater_or_equal(fraction, half)) {
      *result = bin_add(unsigned_truncated, Decimal(1));
    } else {
      *result = unsigned_truncated;
    }
    set_sign(result, sign);
  }
  return code;
}