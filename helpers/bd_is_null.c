#include "../s21_decimal.h"

int bd_is_null(big_decimal bd) {
  return is_null(bd.decimals[0]) && is_null(bd.decimals[1]);
}