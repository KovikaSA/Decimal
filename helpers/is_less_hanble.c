#include "../s21_decimal.h"

int is_less_handle(s21_decimal d1, s21_decimal d2) {
  int code = 0;
  big_decimal bd1;
  big_decimal bd2;
  rescaling(d1, d2, &bd1, &bd2);
  int compare = bd_bin_cmp(bd1, bd2);
  if (compare == -1) {
    code = 1;
  } else {
    code = 0;
  }
  return code;
}