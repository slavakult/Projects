#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DECIMAL 79228162514264337593543950335.0F
#define SCALE 0x00ff0000
#define MINUS 0x80000000
#define MASK_0 0b00000000000000000000000000000000

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int bank_round(s21_big_decimal num);
int simple_add(s21_big_decimal value_1, s21_big_decimal value_2,
               s21_big_decimal *result);
void simple_div(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result, s21_big_decimal *decimal_buffer);
void simple_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);
void mul_change_sign(s21_big_decimal *result, s21_big_decimal num1,
                     s21_big_decimal num2);
int setScale(s21_decimal *value, int scale);
int decimal_limit(s21_decimal num);

void move_left(s21_big_decimal *num, int move);
void increase_on_10(s21_big_decimal *num);
void reduce_on_10(s21_big_decimal *num);
int find_one(s21_big_decimal num, int *index, int *bits_index);
int bit(int binary_num, int digit);
void to_null_big_decimal(s21_big_decimal *num);
void copy_big_decimal(s21_big_decimal *dst, s21_big_decimal source);
void copy_decimal(s21_decimal *dst, s21_decimal source);
void write_big_decimal(s21_decimal num, s21_big_decimal *new_num);
void scale_change(s21_big_decimal *num, char sign, int how_much, int adapt);
int ten_scale(s21_big_decimal num1);
void normalize(s21_big_decimal *num1, s21_big_decimal *num2);
int big_decimal_not_null(s21_big_decimal num);
void back_to_decimal(s21_big_decimal *source, s21_decimal *dst,
                     int *flag_result);
void back_to_decimal_without_flag(s21_big_decimal source, s21_decimal *dst);
void back_to_decimal_for_others(s21_big_decimal *source, s21_decimal *dst,
                                int *flag_result);
int xor (int a, int b);

#endif