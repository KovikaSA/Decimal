#include "../s21_decimal.h"

int get_empty1(s21_decimal value) {
  service_bits service;
  service.bits = value.bits[3];
  return service.parts.empty1;
}

int get_empty2(s21_decimal value) {
  service_bits service;
  service.bits = value.bits[3];
  return service.parts.empty2;
}