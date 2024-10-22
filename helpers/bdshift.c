#include "../s21_decimal.h"

big_decimal bdshift(big_decimal value, int dir, int amount) {
  big_decimal result = value;
  for (int count = 0; count < amount; count++) {
    int j = dir ? ALL_BITS - 1 : 0;
    int bit = get_bit(result.decimals[1 - dir], j);
    result.decimals[0] = bshift(result.decimals[0], dir, 1);
    result.decimals[1] = bshift(result.decimals[1], dir, 1);
    if (bit) {
      result.decimals[dir] =
          set_bit(result.decimals[dir], dir ? 0 : ALL_BITS - 1);
    }
  }
  return result;
}
