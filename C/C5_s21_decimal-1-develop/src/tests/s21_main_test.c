#include "s21_main_test.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

int main(void) {
  int failed = 0;
  Suite *s21_add, *s21_sub, *s21_mul, *s21_div, *s21_is_less, *s21_is_greater,
      *s21_is_greater_equal, *s21_is_less_equal, *s21_is_equal,
      *s21_is_not_equal, *s21_from_int_to_decimal, *s21_from_float_to_decimal,
      *s21_floor, *s21_round, *s21_truncate, *s21_negate;
  SRunner *runner_add, *runner_sub, *runner_mul, *runner_div, *runner_is_less,
      *runner_is_greater, *runner_is_greater_equal, *runner_is_less_equal,
      *runner_is_equal, *runner_is_not_equal, *runner_from_int_to_decimal,
      *runner_from_float_to_decimal, *runner_floor, *runner_round,
      *runner_truncate, *runner_negate;

  s21_add = suite_add();
  s21_sub = suite_sub();
  s21_mul = suite_mul();
  s21_div = suite_div();
  s21_is_less = suite_is_less();
  s21_is_greater = suite_is_greater();
  s21_is_greater_equal = suite_is_greater_equal();
  s21_is_less_equal = suite_is_less_equal();
  s21_is_equal = suite_is_equal();
  s21_is_not_equal = suite_is_not_equal();
  s21_from_int_to_decimal = suite_from_int_to_decimal();
  s21_from_float_to_decimal = suite_from_float_to_decimal();
  s21_floor = suite_floor();
  s21_round = suite_round();
  s21_truncate = suite_truncate();
  s21_negate = suite_negate();

  runner_add = srunner_create(s21_add);
  srunner_run_all(runner_add, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_add);
  srunner_free(runner_add);

  runner_sub = srunner_create(s21_sub);
  srunner_run_all(runner_sub, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_sub);
  srunner_free(runner_sub);

  runner_mul = srunner_create(s21_mul);
  srunner_run_all(runner_mul, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_mul);
  srunner_free(runner_mul);

  runner_div = srunner_create(s21_div);
  srunner_run_all(runner_div, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_div);
  srunner_free(runner_div);

  runner_is_less = srunner_create(s21_is_less);
  srunner_run_all(runner_is_less, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_is_less);
  srunner_free(runner_is_less);

  runner_is_greater = srunner_create(s21_is_greater);
  srunner_run_all(runner_is_greater, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_is_greater);
  srunner_free(runner_is_greater);

  runner_is_greater_equal = srunner_create(s21_is_greater_equal);
  srunner_run_all(runner_is_greater_equal, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_is_greater_equal);
  srunner_free(runner_is_greater_equal);

  runner_is_less_equal = srunner_create(s21_is_less_equal);
  srunner_run_all(runner_is_less_equal, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_is_less_equal);
  srunner_free(runner_is_less_equal);

  runner_is_equal = srunner_create(s21_is_equal);
  srunner_run_all(runner_is_equal, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_is_equal);
  srunner_free(runner_is_equal);

  runner_is_not_equal = srunner_create(s21_is_not_equal);
  srunner_run_all(runner_is_not_equal, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_is_not_equal);
  srunner_free(runner_is_not_equal);

  runner_from_int_to_decimal = srunner_create(s21_from_int_to_decimal);
  srunner_run_all(runner_from_int_to_decimal, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_from_int_to_decimal);
  srunner_free(runner_from_int_to_decimal);

  runner_from_float_to_decimal = srunner_create(s21_from_float_to_decimal);
  srunner_run_all(runner_from_float_to_decimal, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_from_float_to_decimal);
  srunner_free(runner_from_float_to_decimal);

  runner_floor = srunner_create(s21_floor);
  srunner_run_all(runner_floor, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_floor);
  srunner_free(runner_floor);

  runner_round = srunner_create(s21_round);
  srunner_run_all(runner_round, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_round);
  srunner_free(runner_round);

  runner_truncate = srunner_create(s21_truncate);
  srunner_run_all(runner_truncate, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_truncate);
  srunner_free(runner_truncate);

  runner_negate = srunner_create(s21_negate);
  srunner_run_all(runner_negate, CK_NORMAL);
  failed = failed + srunner_ntests_failed(runner_negate);
  srunner_free(runner_negate);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
