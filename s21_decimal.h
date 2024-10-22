#ifndef SRC_S21_DECIMAL
#define SRC_S21_DECIMAL

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

typedef struct big_decimal {
  s21_decimal decimals[2];
} big_decimal;

#define ALL_BITS 128
#define INT_SIZE 32
#define BASE_SIZE 96

#define MAX_FLOAT 79228157791897854723898736640.0f
#define MIN_FLOAT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

static const s21_decimal ten_pows[39] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
    [29] = {{0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x1}},
    [30] = {{0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0xC}},
    [31] = {{0x80000000, 0xC0914B26, 0x37BE2022, 0x7E}},
    [32] = {{0x0, 0x85ACEF81, 0x2D6D415B, 0x4EE}},
    [33] = {{0x0, 0x38C15B0A, 0xC6448D93, 0x314D}},
    [34] = {{0x0, 0x378D8E64, 0xBEAD87C0, 0x1ED09}},
    [35] = {{0x0, 0x2B878FE8, 0x72C74D82, 0x134261}},
    [36] = {{0x0, 0xB34B9F10, 0x7BC90715, 0xC097CE}},
    [37] = {{0x0, 0xF436A0, 0xD5DA46D9, 0x785EE10}},
    [38] = {{0x0, 0x98A2240, 0x5A86C47A, 0x4B3B4CA8}}};

typedef union service_bits {
  int bits;
  struct {
    unsigned int empty2 : 16;
    unsigned int scale : 8;
    unsigned int empty1 : 7;
    unsigned int sign : 1;
  } parts;
} service_bits;

#define RIGHT 0
#define LEFT 1

typedef int (*Op)(int, int);

/************ ARITHMETICS FUNCTIONS ************/
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/************ COMPARISON FUNCTIONS ************/
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);

/************ CONVERTER FUNCTIONS ************/
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/************ ADDITIONAL FUNCTIONS ************/
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/************ HELPERS FUNCTIONS ************/
int add_handle(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
               int action);
int div_handle(big_decimal quotient, big_decimal divisor, big_decimal rem,
               s21_decimal *res);
int mul_handle(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal Decimal(int number);
s21_decimal min_int(void);
s21_decimal max_int(void);
void clear(s21_decimal *decimal);
s21_decimal decimal_abs(s21_decimal value_1);
int get_sign(s21_decimal value);
int is_correct(s21_decimal value);
void set_sign(s21_decimal *value, int sign);
int is_null(s21_decimal value);

big_decimal bd_bin_div(big_decimal d1, big_decimal d2, big_decimal *rem);
big_decimal tobd(s21_decimal value);
void rescaling(s21_decimal d1, s21_decimal d2, big_decimal *bd1,
               big_decimal *bd2);

s21_decimal remove_trailing_zeros(s21_decimal value);
int is_less_handle(s21_decimal d1, s21_decimal d2);
int get_scale(s21_decimal value);
int get_bit(s21_decimal value, int index);
s21_decimal float_string_to_decimal(char *str);
s21_decimal round_banking(s21_decimal integral, s21_decimal fractional);
void set_scale(s21_decimal *decimal, int scale);
s21_decimal ten_pow(int pow);
int get_decimal_shift(big_decimal value);
big_decimal bd_bin_add(big_decimal d1, big_decimal d2);
int s21_max(int value_1, int value_2);
big_decimal bd_bin_sub(big_decimal d1, big_decimal d2);
s21_decimal decimal_logic(s21_decimal d1, s21_decimal d2, Op op);
big_decimal bdshift(big_decimal value, int dir, int amount);
s21_decimal zerofive(void);
int _and(int a, int b);
int _xor(int a, int b);
s21_decimal set_bit(s21_decimal value, int index);
int get_significants(s21_decimal value);
int bd_is_null(big_decimal bd);
int bd_bin_cmp(big_decimal d1, big_decimal d2);
int bin_cmp(s21_decimal d1, s21_decimal d2);
s21_decimal invert(s21_decimal value);
s21_decimal bshift(s21_decimal value, int dir, int amount);
int calc_fractional(big_decimal *quotient, big_decimal divisor,
                    big_decimal *rem);
big_decimal bd_bin_mul(big_decimal d1, s21_decimal d2);
int get_exp(char *str);
s21_decimal max_decimal(void);
int get_empty1(s21_decimal value);
int get_empty2(s21_decimal value);
void clear_service(s21_decimal *value);
s21_decimal bin_add(s21_decimal d1, s21_decimal d2);
int is_even(s21_decimal value);
#endif