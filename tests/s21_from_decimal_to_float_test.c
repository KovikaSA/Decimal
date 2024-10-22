#include "../s21_decimal.h"
#include "s21_decimal_test.h"

static s21_decimal array[] = {
    {{0x000026B9, 0x00000000, 0x00000000, 0x00030000}},  // 9.913
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 2
    {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},  // -2
    {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}},  // 1.5
    {{0x0000000F, 0x00000000, 0x00000000, 0x80010000}},  // -1.5
    {{0x00000009, 0x00000000, 0x00000000, 0x00010000}},  // 0.9
    {{0x00000009, 0x00000000, 0x00000000, 0x80010000}},  // -0.9
    {{0x00000001, 0x00000000, 0x00000000, 0x80010000}},  // -0.1
    {{0x00000001, 0x00000000, 0x00000000, 0x00010000}},  // 0.1
    {{0x0000000B, 0x00000000, 0x00000000, 0x80010000}},  // -1.1
    {{0x0000000B, 0x00000000, 0x00000000, 0x00010000}},  // 1.1
    {{0x000031DD, 0x00000000, 0x00000000, 0x00030000}},  // 12.765
    {{0x00002F0D, 0x00000000, 0x00000000, 0x80030000}},  // -12.045
    {{0x0001869F, 0x00000000, 0x00000000, 0x00040000}},  // 9.9999
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // -79228162514264337593543950335 /// 22
    {{0x000000D3, 0x00007C45, 0x00007C57,
      0x80080000}},  // -5871783107468845.32076755
    {{0x003A6E50, 0x007F1483, 0x003215CF,
      0x00020000}},  // 605492791886648540813348.64
    {{0x00000000, 0x00000000, 0x00000000, 0x800A0000}},  // 0.0000000000
    {{0xF533512E, 0x0000004B, 0x00000000, 0x00060000}},  // 326236.328238
    {{0x51A337CD, 0x00000002, 0x00000000, 0x80040000}},  // -995958.5741
    {{0xDC425734, 0x01C068FA, 0x00000000, 0x00070000}},  // 12621621621.2821812
    {{0xCC133B70, 0x004D86D4, 0x00000000, 0x000B0000}},  // 218218.21721721712
    {{0x00000001, 0x00000000, 0x00000000,
      0x00140000}},  // 0.00000000000000000001
};

static float result[] = {
    9.91300011f,
    0.f,
    1.f,
    -1.f,
    2.f,
    -2.f,
    1.5f,
    -1.5f,
    0.899999976f,
    -0.899999976f,
    -0.100000001f,
    0.100000001f,
    -1.10000002f,
    1.10000002f,
    12.7650003f,
    -12.0450001f,
    9.99989986f,
    79228162500000000000000000000.f,
    -79228162500000000000000000000.f,  /// 22
    -5871782930000000.f,
    605492757000000000000000.f,
    0.f,
    326236.343750,
    -995958.563f,
    12621621200.f,
    218218.219f,
    9.99999968E-21f,
};

static s21_decimal error_array[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x000026B9, 0x00000000, 0x00000000, 0x00030100}},
    {{0x00000000, 0x00000000, 0x00000000, 0x0A000000}},
};

START_TEST(test_from_decimal_to_float) {
  float tmp = 0;
  int code = s21_from_decimal_to_float(array[_i], &tmp);
  ck_assert_float_eq(tmp, result[_i]);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_with_error) {
  float empty = 0;
  float *tmp = _i == 0 ? NULL : &empty;
  int code = s21_from_decimal_to_float(error_array[_i], tmp);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("FROM_DECIMAL_TO_FLOAT");
  tc_core = tcase_create("Core");

  tcase_add_loop_test(tc_core, test_from_decimal_to_float, 0,
                      sizeof(array) / sizeof(s21_decimal));
  tcase_add_loop_test(tc_core, test_from_decimal_to_float_with_error, 0,
                      sizeof(error_array) / sizeof(s21_decimal));
  suite_add_tcase(s, tc_core);

  return s;
}
