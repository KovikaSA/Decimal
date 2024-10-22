#include "../s21_decimal.h"

void set_scale(s21_decimal *decimal, int scale) {
  service_bits service;
  service.bits = decimal->bits[3];
  service.parts.scale = scale;
  decimal->bits[3] = service.bits;
}