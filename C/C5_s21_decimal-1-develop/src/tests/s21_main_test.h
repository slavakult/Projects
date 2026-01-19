#ifndef S21_MAIN_TEST_H
#define S21_MAIN_TEST_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_INF_POS (+1.0 / 0.0)
#define S21_INF_NEG (-1.0 / 0.0)

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_mul(void);
Suite *suite_div(void);

Suite *suite_is_less(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_equal(void);
Suite *suite_is_less_equal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);

Suite *suite_from_int_to_decimal(void);
Suite *suite_from_float_to_decimal(void);

Suite *suite_floor(void);
Suite *suite_round(void);
Suite *suite_truncate(void);
Suite *suite_negate(void);

#endif