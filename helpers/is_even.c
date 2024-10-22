#include "../s21_decimal.h"

int is_even(s21_decimal value) { return (value.bits[0] & 1) != 1; }