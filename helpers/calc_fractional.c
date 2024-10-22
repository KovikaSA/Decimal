#include "../s21_decimal.h"

int calc_fractional(big_decimal *quotient, big_decimal divisor,
                    big_decimal *rem) {
  int scale = 0;
  int flag = 0;
  big_decimal tmp;
  while ((!is_null((*rem).decimals[0]) || !is_null((*rem).decimals[1])) &&
         scale < 28 && !flag) {
    big_decimal s_quotient = *quotient;
    big_decimal s_rem = *rem;
    *quotient = bd_bin_mul(*quotient, Decimal(10));
    *rem = bd_bin_mul(*rem, Decimal(10));
    tmp = bd_bin_div(*rem, divisor, rem);
    *quotient = bd_bin_add(*quotient, tmp);
    if (!is_correct((*quotient).decimals[0])) {
      *quotient = s_quotient;
      *rem = s_rem;
      flag = 1;
    } else {
      scale++;
    }
  }
  return scale;
}