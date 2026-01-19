#include "./s21_decimal.h"

void simple_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result) {
  s21_big_decimal value_1_copy = {0};
  copy_big_decimal(&value_1_copy, value_1);
  s21_big_decimal value_2_copy = {0};
  copy_big_decimal(&value_2_copy, value_2);
  for (int bits_index = 0; bits_index < 7; bits_index++) {
    for (int index = 0; index < 32; index++) {
      int value_1_bit = bit(value_1_copy.bits[bits_index], index);
      int value_2_bit = bit(value_2_copy.bits[bits_index], index);
      if (value_1_bit >= value_2_bit) {
        result->bits[bits_index] |= (value_1_bit - value_2_bit) << index;
      } else {
        int buff_index = index;
        int buff_bits_index = bits_index;
        int one_was_found = 0;
        while (one_was_found == 0) {
          if (buff_index >= 31) {
            buff_index = 0;
            buff_bits_index++;
          } else {
            buff_index++;
          }
          if (bit(value_1_copy.bits[buff_bits_index], buff_index) == 1) {
            int mask = MASK_0;
            one_was_found = 1;
            mask |= ~(1U << buff_index);
            value_1_copy.bits[buff_bits_index] &= mask;

            while (
                !((buff_bits_index == bits_index) && (buff_index == index))) {
              if (buff_index <= 0) {
                buff_index = 31;
                buff_bits_index--;
              } else {
                buff_index--;
              }
              mask &= MASK_0;
              mask |= (1U << buff_index);
              value_1_copy.bits[buff_bits_index] |= mask;
            }
            result->bits[bits_index] |= 1U << index;
          }
        }
      }
    }
  }
}

void mul_change_sign(s21_big_decimal *result, s21_big_decimal num1,
                     s21_big_decimal num2) {
  int sign_1 = bit(num1.bits[7], 31);
  int sign_2 = bit(num2.bits[7], 31);
  if (sign_1 != sign_2) {
    unsigned int mask = MASK_0;
    mask |= (1U << 31);
    result->bits[7] |= mask;
  } else {
    unsigned int mask = MASK_0;
    mask |= ~(1U << 31);
    result->bits[7] &= mask;
  }
}

int simple_add(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result) {
  int carry = 0;
  for (int bits_index = 0; bits_index < 7; bits_index++) {
    result->bits[bits_index] = MASK_0;
    for (int index = 0; index < 32; index++) {
      int value_1_bit = bit(value_1.bits[bits_index], index);
      int value_2_bit = bit(value_2.bits[bits_index], index);
      result->bits[bits_index] += (carry ? !xor(value_1_bit, value_2_bit)
                                         : xor(value_1_bit, value_2_bit))
                                  << index;

      if (value_1_bit + value_2_bit + carry >= 2) {
        carry = 1;
      } else {
        carry = 0;
      }
    }
  }
  return 1;
}

int bit(int binary_num, int digit) {
  int result = 1 & (binary_num >> (digit % 32));
  return (result);
}

int xor
    (int a, int b) {
      int result = (a | b) & (!(a & b));
      return (result);
    }

    void write_big_decimal(s21_decimal num, s21_big_decimal *new_num) {
  new_num->bits[0] = num.bits[0];
  new_num->bits[1] = num.bits[1];
  new_num->bits[2] = num.bits[2];
  for (int i = 3; i < 7; i++) {
    new_num->bits[i] = MASK_0;
  }
  new_num->bits[7] = num.bits[3];
}

void move_left(s21_big_decimal *num, int move) {
  for (int bits_index = 6; bits_index >= 0; bits_index--) {
    for (int index = 31; index >= 0; index--) {
      if ((bits_index + (index + move) / 32) <= 6) {
        int from = bit(num->bits[bits_index], index);
        int to = bit(num->bits[bits_index + (index + move) / 32],
                     (index + move) % 32);
        if (from != to) {
          unsigned int mask = MASK_0;
          if (to == 0) {
            mask |= (1U << (index + move) % 32);
            num->bits[bits_index + (index + move) / 32] |= mask;
          } else {
            mask |= ~(1U << (index + move) % 32);
            num->bits[bits_index + (index + move) / 32] &= mask;
          }
        }
      }
      int null_mask = MASK_0;
      null_mask |= ~(1 << index);
      num->bits[bits_index] &= null_mask;
    }
  }
}

int find_one(s21_big_decimal num, int *index, int *bits_index) {
  int flag = 0;
  if (big_decimal_not_null(num)) {
    flag = 1;
    while (bit(num.bits[*bits_index], *index) != 1) {
      if ((*index) <= 0) {
        (*index) = 31;
        (*bits_index)--;
      } else {
        (*index)--;
      }
    }
  }
  return (flag);
}

void reduce_on_10(s21_big_decimal *num) {
  int index = 31, bits_index = 6;
  s21_big_decimal result = {0};

  scale_change(num, '-', 1, ten_scale(*num));
  if (find_one(*num, &index, &bits_index)) {
    int decimal_buffer = 0;
    result.bits[7] = num->bits[7];
    while (bits_index >= 0) {
      decimal_buffer *= 2;
      decimal_buffer += bit(num->bits[bits_index], index);
      if (decimal_buffer < 10) {
        move_left(&result, 1);
      } else {
        move_left(&result, 1);
        result.bits[0] += 1;
        decimal_buffer -= 10;
      }
      if (index <= 0) {
        index = 31;
        bits_index--;
      } else {
        index--;
      }
    }
    to_null_big_decimal(num);
    copy_big_decimal(num, result);
  }
}

void increase_on_10(s21_big_decimal *num) {
  s21_big_decimal ten = {0};
  s21_big_decimal thousand = {0};
  int seven_bit = num->bits[7];
  copy_big_decimal(&ten, *num);
  copy_big_decimal(&thousand, *num);
  move_left(&ten, 1);
  move_left(&thousand, 3);
  simple_add(ten, thousand, num);
  num->bits[7] = seven_bit;
  scale_change(num, '+', 1, ten_scale(*num));
}

void copy_big_decimal(s21_big_decimal *dst, s21_big_decimal src) {
  to_null_big_decimal(dst);
  for (int i = 0; i <= 7; i++) {
    dst->bits[i] |= src.bits[i];
  }
}

void copy_decimal(s21_decimal *dst, s21_decimal src) {
  for (int i = 0; i <= 3; i++) {
    dst->bits[i] |= src.bits[i];
  }
}

void to_null_big_decimal(s21_big_decimal *num) {
  for (int i = 0; i <= 7; i++) {
    num->bits[i] = MASK_0;
  }
}

int ten_scale(s21_big_decimal num1) {
  int decimal_buffer = 0;
  for (int i = 23; i >= 16; i--) {
    decimal_buffer *= 2;
    decimal_buffer += bit(num1.bits[7], i);
  }
  return (decimal_buffer);
}

void normalize(s21_big_decimal *num1, s21_big_decimal *num2) {
  int adap_dec_1 = ten_scale(*num1);
  int adap_dec_2 = ten_scale(*num2);
  if (adap_dec_1 > 28) {
    for (int i = 0; i < adap_dec_1 - 28; i++) {
      reduce_on_10(num1);
    }
    adap_dec_1 = 28;
  }
  if (adap_dec_2 > 28) {
    for (int i = 0; i < adap_dec_2 - 28; i++) {
      reduce_on_10(num2);
    }
    adap_dec_2 = 28;
  }
  while (adap_dec_1 != adap_dec_2) {
    if (adap_dec_1 > adap_dec_2) {
      increase_on_10(num2);
      adap_dec_2++;
    } else {
      increase_on_10(num1);
      adap_dec_1++;
    }
  }
}

void scale_change(s21_big_decimal *num, char sign, int how_much, int adapt) {
  if (sign == '+') adapt += how_much;
  if (sign == '-') adapt -= how_much;
  for (int i = 16; i <= 23; i++) {
    unsigned int mask = MASK_0;
    mask |= ~(1U << i);
    num->bits[7] &= mask;
    num->bits[7] |= (bit(adapt, i - 16) << i);
  }
}

void back_to_decimal_without_flag(s21_big_decimal src,
                                  s21_decimal *current_bit) {
  current_bit->bits[0] = src.bits[0];
  current_bit->bits[1] = src.bits[1];
  current_bit->bits[2] = src.bits[2];
  current_bit->bits[3] = src.bits[7];
}

int big_decimal_not_null(s21_big_decimal num) {
  int is_null = 1;
  if (num.bits[0] == 0 && num.bits[1] == 0 && num.bits[2] == 0 &&
      num.bits[3] == 0 && num.bits[4] == 0 && num.bits[5] == 0 &&
      num.bits[6] == 0) {
    is_null = 0;
  }
  return (is_null);
}

int decimal_limit(s21_decimal num) {
  int flag = 0;
  s21_big_decimal decimal_buffer = {0};
  write_big_decimal(num, &decimal_buffer);
  if (ten_scale(decimal_buffer) > 28) flag = 1;
  for (int i = 0; i < 16; i++) {
    if (bit(decimal_buffer.bits[7], i) == 1) {
      flag = 1;
    }
  }
  for (int i = 24; i < 31; i++) {
    if (bit(decimal_buffer.bits[7], i) == 1) {
      flag = 1;
    }
  }
  return flag;
}

void back_to_decimal(s21_big_decimal *src, s21_decimal *dst, int *flag_result) {
  int flag_null = big_decimal_not_null(*src);
  while (ten_scale(*src) > 28) {
    if (bank_round(*src) == 1) {
      reduce_on_10(src);
      s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      s21_big_decimal result_big_decimal = {0};
      result_big_decimal.bits[7] = src->bits[7];
      simple_add(*src, one, &result_big_decimal);
      to_null_big_decimal(src);
      copy_big_decimal(src, result_big_decimal);
    } else
      reduce_on_10(src);
  }
  if (big_decimal_not_null(*src) != flag_null) *flag_result = 2;
  while ((src->bits[3] > 0 || src->bits[4] > 0 || src->bits[5] > 0 ||
          src->bits[6] > 0) &&
         ten_scale(*src) > 0) {
    if (bank_round(*src) == 1) {
      reduce_on_10(src);
      s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
      s21_big_decimal result_big_decimal = {0};
      result_big_decimal.bits[7] = src->bits[7];
      simple_add(*src, one, &result_big_decimal);
      to_null_big_decimal(src);
      copy_big_decimal(src, result_big_decimal);
    } else
      reduce_on_10(src);
  }

  if ((src->bits[3] > 0 || src->bits[4] > 0 || src->bits[5] > 0 ||
       src->bits[6] > 0) &&
      ten_scale(*src) == 0) {
    if (bit(src->bits[7], 31) == 0) {
      *flag_result = 1;
    } else {
      *flag_result = 2;
    }
  }
  if (*flag_result > 0) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
  } else {
    dst->bits[0] = src->bits[0];
    dst->bits[1] = src->bits[1];
    dst->bits[2] = src->bits[2];
    dst->bits[3] = src->bits[7];
  }
}

void back_to_decimal_for_others(s21_big_decimal *src, s21_decimal *dst,
                                int *flag_result) {
  int flag_null = big_decimal_not_null(*src);
  while (ten_scale(*src) > 28) {
    reduce_on_10(src);
  }
  if (big_decimal_not_null(*src) != flag_null) *flag_result = 1;
  while ((src->bits[3] > 0 || src->bits[4] > 0 || src->bits[5] > 0 ||
          src->bits[6] > 0) &&
         ten_scale(*src) > 0) {
    reduce_on_10(src);
  }
  if ((src->bits[3] > 0 || src->bits[4] > 0 || src->bits[5] > 0 ||
       src->bits[6] > 0) &&
      ten_scale(*src) == 0) {
    *flag_result = 1;
  }
  if (*flag_result > 0) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
  } else {
    dst->bits[0] = src->bits[0];
    dst->bits[1] = src->bits[1];
    dst->bits[2] = src->bits[2];
    dst->bits[3] = src->bits[7];
  }
}

int setScale(s21_decimal *value, int scale) {
  int res = 1;
  if (scale <= 28 && scale >= 0) {
    res = 0;
    value->bits[3] &= MINUS;
    value->bits[3] |= (scale << 16) & SCALE;
  }
  return res;
}

int bank_round(s21_big_decimal num) {
  int flag = 0;
  s21_big_decimal decimal_buffer = {0};
  s21_big_decimal temp_buffer = {0};
  s21_big_decimal result_big_decimal = {0};
  copy_big_decimal(&decimal_buffer, num);
  copy_big_decimal(&temp_buffer, num);
  reduce_on_10(&temp_buffer);
  increase_on_10(&temp_buffer);
  simple_sub(decimal_buffer, temp_buffer, &result_big_decimal);
  reduce_on_10(&decimal_buffer);
  int sub_value = result_big_decimal.bits[0];
  if (sub_value > 5) {
    flag = 1;
  }
  if (sub_value == 5 && bit(decimal_buffer.bits[0], 0) == 1) {
    flag = 1;
  }
  return flag;
}