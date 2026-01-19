#include "./s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  if (isnan(src) || isinf(src) || fabs(src) > MAX_DECIMAL) result = 1;
  if (dst && !result) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    int sign = 0;
    if (src < 0) {
      sign = 1;
      src = fabs(src);
    }
    int temp = (int)src;
    int scale = 0;
    while (src - ((float)temp / (int)(pow(10, scale))) != 0) {
      scale++;
      temp = src * (int)(pow(10, scale));
    }
    s21_from_int_to_decimal(temp, dst);
    if (sign) s21_negate(*dst, dst);
    setScale(dst, scale);
  } else {
    result = 1;
  }
  return result;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 0;
  s21_big_decimal decimal_buffer = {0};
  write_big_decimal(src, &decimal_buffer);
  float num_0 = (float)src.bits[0];
  float num_1 = (float)src.bits[1] * pow(2.0, 32.0);
  float num_2 = (float)src.bits[2] * pow(2.0, 64.0);
  float sign = 1.0;
  if (bit(src.bits[3], 31)) {
    sign *= -1.0;
  }
  int ten_scale_buff = ten_scale(decimal_buffer);
  if (ten_scale_buff > 28) {
    result = 1;
  } else {
    *dst = sign * (num_0 + num_1 + num_2) * powf(10, -ten_scale_buff);
  }
  return (result);
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;
  for (int i = 0; i <= 3; i++) {
    dst->bits[i] = MASK_0;
  }
  if (src < 0) {
    int mask = MASK_0;
    mask = (1U << 31);
    dst->bits[3] |= mask;
    dst->bits[0] = src * (-1);
  } else
    dst->bits[0] = src;
  return result;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_big_decimal decimal_buffer = {0};
  write_big_decimal(src, &decimal_buffer);
  while (ten_scale(decimal_buffer) > 0) {
    reduce_on_10(&decimal_buffer);
  }
  int result = 0;
  for (int i = 6; i > 0; i--) {
    if (decimal_buffer.bits[i] != 0) {
      result = 1;
    }
  }
  if (result == 0) {
    *dst = decimal_buffer.bits[0];
    if (bit(decimal_buffer.bits[7], 31) == 1) {
      *dst = (*dst) * (-1);
    }
  }
  return result;
}
