#ifndef TEST
#define TEST

#include <check.h>

#include "../s21_matrix.h"

Suite *suite_create_m(void);
Suite *suite_remove(void);
Suite *suite_eq(void);
Suite *suite_sum(void);
Suite *suite_sub(void);
Suite *suite_mult_number(void);
Suite *suite_mult(void);
Suite *suite_transpose(void);
Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse(void);

double get_rand(double min, double max);

#endif