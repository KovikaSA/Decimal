#include "../s21_decimal.h"

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  int result = 0;
  int sign1 = get_sign(value1);
  int sign2 = get_sign(value2);
  if (s21_is_equal(value1, Decimal(0)) && s21_is_equal(value2, Decimal(0))) {
    result = 0;
  } else if (sign1 == 1 && sign2 == 0) {
    result = 1;
  } else if (sign1 == 0 && sign2 == 1) {
    result = 0;
  } else if (sign1 == 1 && sign2 == 1) {
    result = is_less_handle(decimal_abs(value2), decimal_abs(value1));
  } else {
    result = is_less_handle(value1, value2);
  }
  return result;
}