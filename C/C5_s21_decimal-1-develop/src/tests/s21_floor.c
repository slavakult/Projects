#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_floor_1) {
  float test_1 = 1234.56;
  float result = 1234.0;
  s21_decimal test_1_dec = {0};
  s21_from_float_to_decimal(test_1, &test_1_dec);
  s21_floor(test_1_dec, &test_1_dec);
  s21_from_decimal_to_float(test_1_dec, &test_1);

  ck_assert_float_eq(test_1, result);
}
END_TEST

START_TEST(s21_floor_2) {
  float test_1 = 1.256;
  float result = 1.0;
  s21_decimal test_1_dec = {0};
  s21_from_float_to_decimal(test_1, &test_1_dec);
  s21_floor(test_1_dec, &test_1_dec);
  s21_from_decimal_to_float(test_1_dec, &test_1);

  ck_assert_float_eq(test_1, result);
  END_TEST
}

Suite *suite_floor(void) {
  Suite *a = suite_create("Testing S21_FLOOR [Other]");
  TCase *test_1, *test_2;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_floor_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_floor_2);
  suite_add_tcase(a, test_2);

  return a;
}
