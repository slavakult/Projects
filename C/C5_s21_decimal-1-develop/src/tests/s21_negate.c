#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_negate_1) {
  int test_1 = -5000;
  int result = 0;
  int result_second = 5000;

  s21_decimal result_dec = {0};
  s21_from_int_to_decimal(test_1, &result_dec);
  s21_negate(result_dec, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);

  ck_assert_int_eq(result, result_second);
}
END_TEST
START_TEST(s21_negate_2) {
  int test_1 = 5000;
  int result = 0;
  int result_second = -5000;

  s21_decimal result_dec = {0};
  s21_from_int_to_decimal(test_1, &result_dec);
  s21_negate(result_dec, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);

  ck_assert_int_eq(result, result_second);
}
END_TEST
START_TEST(s21_negate_3) {
  float test_1 = 13.0;
  float result = 0.0;
  float result_second = -13.0;

  s21_decimal result_dec = {0};
  s21_from_float_to_decimal(test_1, &result_dec);
  s21_negate(result_dec, &result_dec);
  s21_from_decimal_to_float(result_dec, &result);

  ck_assert_float_eq(result, result_second);
}
END_TEST

START_TEST(s21_negate_4) {
  float test_1 = -13.0;
  float result = 0.0;
  float result_second = 13.0;

  s21_decimal result_dec = {0};
  s21_from_float_to_decimal(test_1, &result_dec);
  s21_negate(result_dec, &result_dec);
  s21_from_decimal_to_float(result_dec, &result);

  ck_assert_float_eq(result, result_second);
}
END_TEST

Suite *suite_negate(void) {
  Suite *a = suite_create("Testing S21_NEGATE [Other]");
  TCase *test_1, *test_2, *test_3, *test_4;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_negate_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_negate_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_negate_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_negate_4);
  suite_add_tcase(a, test_4);

  return a;
}