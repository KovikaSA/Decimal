#include "../s21_decimal.h"

int get_sign(s21_decimal value) {
  service_bits service;
  service.bits = value.bits[3];
  return service.parts.sign;
}