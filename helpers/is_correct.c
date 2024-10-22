#include "../s21_decimal.h"

int is_correct(s21_decimal value) {
  int code = 1;
  if (get_empty1(value) != 0 || get_empty2(value) != 0) {
    code = 0;
  } else {
    int scale = get_scale(value);
    if (scale < 0 || scale > 28) code = 0;
  }
  return code;
}