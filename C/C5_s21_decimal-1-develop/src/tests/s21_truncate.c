#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_truncate_1) {
  float test_1 = -5000.78;
  int result = 0;
  int result_second = -5000;

  s21_decimal result_dec = {0};
  s21_from_float_to_decimal(test_1, &result_dec);
  s21_truncate(result_dec, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);

  ck_assert_int_eq(result, result_second);
}
END_TEST

START_TEST(s21_truncate_2) {
  float test_1 = 1.6;
  int result = 0;
  int result_second = 1;
  s21_decimal test_1_dec = {0};
  s21_decimal result_dec = {0};
  s21_from_float_to_decimal(test_1, &test_1_dec);
  s21_truncate(test_1_dec, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);

  ck_assert_int_eq(result, result_second);
}
END_TEST
START_TEST(s21_truncate_3) {
  float test_1 = 0.8;
  int result = 0;
  int result_second = 0;

  s21_decimal result_dec = {0};
  s21_from_float_to_decimal(test_1, &result_dec);
  s21_truncate(result_dec, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);

  ck_assert_int_eq(result, result_second);
}
END_TEST

START_TEST(s21_truncate_4) {
  float test_1 = 0.4;
  int result = 0;
  int result_second = 0;

  s21_decimal result_dec = {0};
  s21_from_float_to_decimal(test_1, &result_dec);
  s21_truncate(result_dec, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);

  ck_assert_int_eq(result, result_second);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *a = suite_create("Testing S21_TRUNCATE [Other]");
  TCase *test_1, *test_2, *test_3, *test_4;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_truncate_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_truncate_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_truncate_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_truncate_4);
  suite_add_tcase(a, test_4);

  return a;
}
