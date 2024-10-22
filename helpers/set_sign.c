#include "../s21_decimal.h"

void set_sign(s21_decimal *value, int sign) {
  service_bits service;
  service.bits = value->bits[3];
  service.parts.sign = sign;
  value->bits[3] = service.bits;
}