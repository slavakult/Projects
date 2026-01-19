#include "./s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = decimal_limit(value);
  s21_big_decimal dec_buffer = {0};
  if (flag == 0) {
    write_big_decimal(value, &dec_buffer);
    for (int i = 0; i <= 3; i++) {
      result->bits[i] = MASK_0;
    }
    copy_decimal(result, value);
    int sign = bit(dec_buffer.bits[7], 31);
    if (sign == 0) {
      int mask = MASK_0;
      mask = (1U << 31);
      result->bits[3] |= mask;
    } else {
      int mask = MASK_0;
      mask = ~(1U << 31);
      result->bits[3] &= mask;
    }
  }
  return flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = decimal_limit(value);
  s21_big_decimal decimal_buffer = {0};
  if (flag == 0) {
    for (int i = 0; i <= 3; i++) {
      result->bits[i] = MASK_0;
    }
    write_big_decimal(value, &decimal_buffer);
    while (ten_scale(decimal_buffer) > 0) {
      reduce_on_10(&decimal_buffer);
    }
  }
  back_to_decimal_without_flag(decimal_buffer, result);
  return flag;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = decimal_limit(value);
  s21_big_decimal result_big_decimal = {0};
  if (flag == 0) {
    int has_floor_value = 0;
    s21_big_decimal decimal_buffer = {0};
    s21_big_decimal temp_buffer = {0};
    write_big_decimal(value, &decimal_buffer);
    write_big_decimal(value, &temp_buffer);
    while (ten_scale(decimal_buffer) > 0) {
      to_null_big_decimal(&result_big_decimal);
      reduce_on_10(&temp_buffer);
      increase_on_10(&temp_buffer);
      simple_sub(decimal_buffer, temp_buffer, &result_big_decimal);
      if (big_decimal_not_null(result_big_decimal)) {
        has_floor_value = 1;
      }
      reduce_on_10(&decimal_buffer);
    }
    to_null_big_decimal(&result_big_decimal);
    if (has_floor_value == 1 && bit(decimal_buffer.bits[7], 31) == 1) {
      s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      simple_add(decimal_buffer, one, &result_big_decimal);
      result_big_decimal.bits[7] = decimal_buffer.bits[7];
    } else

      copy_big_decimal(&result_big_decimal, decimal_buffer);
    for (int i = 0; i <= 3; i++) {
      result->bits[i] = MASK_0;
    }
  }
  back_to_decimal_for_others(&result_big_decimal, result, &flag);
  return flag;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = decimal_limit(value);
  s21_big_decimal result_big_decimal = {0};
  if (flag == 0) {
    s21_big_decimal decimal_buffer = {0};
    s21_big_decimal temp_buffer = {0};
    write_big_decimal(value, &decimal_buffer);
    write_big_decimal(value, &temp_buffer);
    while (ten_scale(decimal_buffer) > 0) {
      to_null_big_decimal(&result_big_decimal);
      reduce_on_10(&temp_buffer);
      increase_on_10(&temp_buffer);
      simple_sub(decimal_buffer, temp_buffer, &result_big_decimal);
      reduce_on_10(&decimal_buffer);
      reduce_on_10(&temp_buffer);
    }
    int sub_value = result_big_decimal.bits[0];
    to_null_big_decimal(&result_big_decimal);
    if ((sub_value == 5 && bit(decimal_buffer.bits[0], 0) == 1) ||
        sub_value > 5) {
      s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      simple_add(decimal_buffer, one, &result_big_decimal);
      result_big_decimal.bits[7] = decimal_buffer.bits[7];
    } else

      copy_big_decimal(&result_big_decimal, decimal_buffer);
    for (int i = 0; i <= 3; i++) {
      result->bits[i] = MASK_0;
    }
  }
  back_to_decimal_for_others(&result_big_decimal, result, &flag);
  return flag;
}
