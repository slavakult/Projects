#include "./s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (!s21_is_less(value_1, value_2)) result = 1;
  return result;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (!s21_is_less_or_equal(value_1, value_2)) result = 1;
  return result;
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  int flag_equal = 0;
  s21_big_decimal decimal_2 = {0};
  s21_big_decimal decimal_1 = {0};
  write_big_decimal(value_1, &decimal_1);
  write_big_decimal(value_2, &decimal_2);
  normalize(&decimal_1, &decimal_2);
  int bits_index = 6;
  int index = 31;
  if (bit(decimal_2.bits[7], 31) < bit(decimal_1.bits[7], 31))
    result = 1;
  else if (bit(decimal_2.bits[7], 31) == bit(decimal_1.bits[7], 31)) {
    while (!(bits_index == 0 && index == 0) && (flag_equal == 0)) {
      if (index <= 0) {
        index = 31;
        bits_index--;
      } else {
        index--;
      }
      if (bit(decimal_2.bits[bits_index], index) !=
          bit(decimal_1.bits[bits_index], index)) {
        flag_equal = 1;
        if (bit(decimal_2.bits[bits_index], index) >
            bit(decimal_1.bits[bits_index], index)) {
          result = 1;
        }
      }
    }
    if (bit(decimal_2.bits[7], 31) == bit(decimal_1.bits[7], 31) &&
        bit(decimal_1.bits[7], 31) == 1 && flag_equal != 0) {
      result = !result;
    }
  }
  return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (s21_is_equal(value_1, value_2) || s21_is_less(value_1, value_2))
    result = 1;
  return result;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal decimal_2 = {0};
  s21_big_decimal decimal_1 = {0};
  write_big_decimal(value_1, &decimal_1);
  write_big_decimal(value_2, &decimal_2);
  normalize(&decimal_1, &decimal_2);
  int bits_index = 6;
  int index = 31;
  int result = 1;
  if (!big_decimal_not_null(decimal_1) && !big_decimal_not_null(decimal_2))
    result = 1;
  else if ((bit(decimal_2.bits[7], 31) != bit(decimal_1.bits[7], 31)))
    result = 0;
  while (!(bits_index == 0 && index == 0) && (result == 1)) {
    if (index <= 0) {
      index = 31;
      bits_index--;
    } else {
      index--;
    }
    if (bit(decimal_2.bits[bits_index], index) !=
        bit(decimal_1.bits[bits_index], index))
      result = 0;
  }
  return result;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (!s21_is_equal(value_1, value_2)) result = 1;
  return result;
}