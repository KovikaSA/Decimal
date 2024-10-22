#include "../s21_decimal.h"

s21_decimal float_string_to_decimal(char *str) {
  s21_decimal result = Decimal(0);
  int digits = 6;
  char *ptr = str;
  int exp = get_exp(str) - 6;
  for (; *ptr && ((*ptr >= '0' && *ptr <= '9') || *ptr == '.'); ptr++) {
    if (*ptr == '.') continue;
    s21_decimal tmp = Decimal(0);
    s21_mul(Decimal(*ptr - '0'), ten_pow(digits), &tmp);
    s21_add(result, tmp, &result);
    digits--;
  }
  if (exp > 0) {
    s21_mul(result, ten_pow(exp), &result);
  } else if (exp < 0) {
    if (exp < -28) {
      s21_div(result, ten_pow(28), &result);
      exp += 28;
    }
    s21_div(result, ten_pow(-exp), &result);
  }
  return result;
}