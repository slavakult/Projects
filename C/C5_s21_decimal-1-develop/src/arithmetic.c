#include "./s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *value_result) {
  int result = 0, is_not_null = 0;
  s21_big_decimal big_decimal_1 = {0}, big_decimal_2 = {0}, temp_result = {0};
  write_big_decimal(value_1, &big_decimal_2);
  write_big_decimal(value_2, &big_decimal_1);
  int sign_flag = 0;
  if (big_decimal_not_null(big_decimal_1) ||
      big_decimal_not_null(big_decimal_2)) {
    is_not_null = 1;
  }
  normalize(&big_decimal_2, &big_decimal_1);
  if (bit(big_decimal_1.bits[7], 31) == bit(big_decimal_2.bits[7], 31)) {
    simple_add(big_decimal_2, big_decimal_1, &temp_result);
    temp_result.bits[7] = big_decimal_1.bits[7];
  } else {
    int bit_mask = MASK_0;
    s21_decimal value_1_normalized = {0}, value_2_normalized = {0};
    back_to_decimal_without_flag(big_decimal_2, &value_1_normalized);
    back_to_decimal_without_flag(big_decimal_1, &value_2_normalized);
    bit_mask |= ~(1U << 31);
    value_1_normalized.bits[3] &= bit_mask;
    value_2_normalized.bits[3] &= bit_mask;
    bit_mask = 0;
    if (bit(big_decimal_2.bits[7], 31) == 1) {
      bit_mask |= ~(1U << 31);
      big_decimal_2.bits[7] &= bit_mask;
      sign_flag = 1;
    } else if (bit(big_decimal_1.bits[7], 31) == 1) {
      bit_mask |= ~(1U << 31);
      big_decimal_1.bits[7] &= bit_mask;
      sign_flag = 2;
    }
    temp_result.bits[7] = big_decimal_2.bits[7];
    if (s21_is_greater(value_1_normalized, value_2_normalized)) {
      simple_sub(big_decimal_2, big_decimal_1, &temp_result);
      if (sign_flag == 1) {
        bit_mask = 0;
        bit_mask |= (1U << 31);
        temp_result.bits[7] |= bit_mask;
      }
    } else if (s21_is_greater(value_2_normalized, value_1_normalized)) {
      simple_sub(big_decimal_1, big_decimal_2, &temp_result);
      if (sign_flag == 2) {
        bit_mask = 0;
        bit_mask |= (1U << 31);
        temp_result.bits[7] |= bit_mask;
      }
    } else if (s21_is_equal(value_1_normalized, value_2_normalized)) {
      to_null_big_decimal(&temp_result);
      sign_flag = 3;
    }
  }
  if (is_not_null == 1 && big_decimal_not_null(temp_result) == 0 &&
      sign_flag != 3) {
    result = 2;
  }
  back_to_decimal(&temp_result, value_result, &result);
  return (result);
}

int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result_value) {
  int result = 0;
  int is_not_null = 0;
  s21_big_decimal temp_result = {0}, big_decimal_1 = {0}, big_decimal_2 = {0};
  write_big_decimal(value_1, &big_decimal_2);
  write_big_decimal(value_2, &big_decimal_1);
  if (s21_is_not_equal(value_1, value_2)) {
    int bit_mask = MASK_0;
    if (big_decimal_not_null(big_decimal_1) ||
        big_decimal_not_null(big_decimal_2)) {
      is_not_null = 1;
    }
    normalize(&big_decimal_2, &big_decimal_1);
    s21_decimal value_1_dst = {0}, value_2_dst = {0};
    back_to_decimal_without_flag(big_decimal_2, &value_1_dst);
    back_to_decimal_without_flag(big_decimal_1, &value_2_dst);
    if (bit(big_decimal_1.bits[7], 31) != bit(big_decimal_2.bits[7], 31)) {
      simple_add(big_decimal_2, big_decimal_1, &temp_result);
      temp_result.bits[7] = big_decimal_2.bits[7];
    } else {
      if (bit(big_decimal_2.bits[7], 31) == 1) {
        if (s21_is_greater_or_equal(value_1_dst, value_2_dst)) {
          simple_sub(big_decimal_1, big_decimal_2, &temp_result);
          temp_result.bits[7] = big_decimal_2.bits[7];
          bit_mask |= ~(1U << 31);
          temp_result.bits[7] &= bit_mask;
        } else {
          simple_sub(big_decimal_2, big_decimal_1, &temp_result);
          temp_result.bits[7] = big_decimal_2.bits[7];
        }
      } else {
        if (s21_is_greater_or_equal(value_1_dst, value_2_dst)) {
          simple_sub(big_decimal_2, big_decimal_1, &temp_result);
          temp_result.bits[7] = big_decimal_2.bits[7];
        } else if (big_decimal_not_null(big_decimal_2) &&
                   big_decimal_not_null(big_decimal_1)) {
          simple_sub(big_decimal_1, big_decimal_2, &temp_result);
          temp_result.bits[7] = big_decimal_2.bits[7];
          bit_mask |= (1U << 31);
          temp_result.bits[7] |= bit_mask;
        }
      }
    }
  }
  if ((is_not_null == 1 && big_decimal_not_null(temp_result) == 0) ||
      (ten_scale(big_decimal_2) > 28) || ten_scale(big_decimal_1) > 28) {
    result = 2;
  }
  back_to_decimal(&temp_result, result_value, &result);
  return result;
}

int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result_value) {
  int result = 0;
  s21_big_decimal big_decimal_1 = {0}, big_decimal_2 = {0}, temp_result = {0};
  write_big_decimal(value_1, &big_decimal_2);
  write_big_decimal(value_2, &big_decimal_1);
  if (!big_decimal_not_null(big_decimal_1))
    result = 3;
  else {
    s21_big_decimal decimal_buffer = {0}, quot_buffer = {0},
                    remain_buffer = {0}, buff_res_value = {0};
    int new_scale = 0;
    if (ten_scale(big_decimal_2) >= ten_scale(big_decimal_1))
      new_scale = ten_scale(big_decimal_2) - ten_scale(big_decimal_1);
    else {
      while (ten_scale(big_decimal_2) != ten_scale(big_decimal_1)) {
        increase_on_10(&big_decimal_2);
      }
    }
    scale_change(&temp_result, '+', new_scale, 0);
    simple_div(big_decimal_2, big_decimal_1, &temp_result, &decimal_buffer);
    while (big_decimal_not_null(decimal_buffer) && new_scale < 28 &&
           decimal_buffer.bits[3] == 0) {
      to_null_big_decimal(&remain_buffer);
      increase_on_10(&decimal_buffer);
      copy_big_decimal(&remain_buffer, decimal_buffer);
      to_null_big_decimal(&decimal_buffer);
      to_null_big_decimal(&quot_buffer);
      simple_div(remain_buffer, big_decimal_1, &quot_buffer, &decimal_buffer);
      increase_on_10(&temp_result);
      simple_add(temp_result, quot_buffer, &buff_res_value);
      to_null_big_decimal(&temp_result);
      copy_big_decimal(&temp_result, buff_res_value);
      new_scale += 1;
      scale_change(&temp_result, '+', new_scale, 0);
    }
    if (bit(big_decimal_2.bits[7], 31) != bit(big_decimal_1.bits[7], 31)) {
      int bit_mask = MASK_0;
      bit_mask |= 1U << 31;
      temp_result.bits[7] |= bit_mask;
    }
  }
  back_to_decimal(&temp_result, result_value, &result);
  return (result);
}

void simple_div(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result_value,
                s21_big_decimal *decimal_buffer) {
  s21_big_decimal buff_sub = {0};
  s21_decimal buff_fake = {0}, value_2_dst = {0};
  back_to_decimal_without_flag(value_2, &value_2_dst);
  value_2_dst.bits[3] &= 0;
  int index = 31, bits_index = 6;
  if (find_one(value_1, &index, &bits_index)) {
    while (bits_index >= 0) {
      move_left(decimal_buffer, 1);
      decimal_buffer->bits[0] += bit(value_1.bits[bits_index], index);
      back_to_decimal_without_flag(*decimal_buffer, &buff_fake);
      if (s21_is_less(buff_fake, value_2_dst)) {
        move_left(result_value, 1);
      } else {
        move_left(result_value, 1);
        result_value->bits[0] += 1;
        to_null_big_decimal(&buff_sub);
        simple_sub(*decimal_buffer, value_2, &buff_sub);
        to_null_big_decimal(decimal_buffer);
        copy_big_decimal(decimal_buffer, buff_sub);
      }
      if (index <= 0) {
        index = 31;
        bits_index--;
      } else {
        index--;
      }
    }
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result_value) {
  int result = 0;
  s21_big_decimal big_decimal_1 = {0}, big_decimal_2 = {0}, temp_result = {0},
                  temp_num = {0};
  write_big_decimal(value_1, &big_decimal_2);
  write_big_decimal(value_2, &big_decimal_1);
  if (big_decimal_not_null(big_decimal_1) &&
      big_decimal_not_null(big_decimal_2)) {
    int one_index = 31, start_index = 0;
    int one_bits = 6, start_bits = 0;
    find_one(big_decimal_2, &one_index, &one_bits);
    int iteartions = (one_bits * 32 + one_index + 1);
    for (int i = 0; i < iteartions; i++) {
      if (bit(big_decimal_2.bits[start_bits], start_index) == 1) {
        simple_add(big_decimal_1, temp_result, &temp_num);
        copy_big_decimal(&temp_result, temp_num);
      }
      move_left(&big_decimal_1, 1);
      if (start_index >= 31) {
        start_index = 0;
        start_bits++;
      } else {
        start_index++;
      }
    }
    int new_scale = ten_scale(big_decimal_2) + ten_scale(big_decimal_1);
    scale_change(&temp_result, '+', new_scale, 0);
  }
  mul_change_sign(&temp_result, big_decimal_1, big_decimal_2);
  back_to_decimal(&temp_result, result_value, &result);
  return (result);
}
