#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal val = {0};
  float start = 0.0;
  float result = 0.0;
  s21_from_float_to_decimal(start, &val);
  s21_from_decimal_to_float(val, &result);

  ck_assert_int_eq(start, result);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal val = {0};
  float start = 1.0;
  float result = 1.0;
  s21_from_float_to_decimal(start, &val);
  s21_from_decimal_to_float(val, &result);

  ck_assert_int_eq(start, result);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal val = {0};
  float start = 566553.5;
  float result = 0.0;
  s21_from_float_to_decimal(start, &val);
  s21_from_decimal_to_float(val, &result);

  ck_assert_float_eq(start, result);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal val = {0};
  float start = -0.256;
  float result = 0.0;
  s21_from_float_to_decimal(start, &val);
  s21_from_decimal_to_float(val, &result);

  ck_assert_float_eq(round(start * 1000), round(result * 1000));
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  s21_decimal val = {0};
  float start = 0.256;
  float result = 0.0;
  s21_from_float_to_decimal(start, &val);
  s21_from_decimal_to_float(val, &result);

  ck_assert_float_eq(round(start * 1000), round(result * 1000));
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal val = {0};
  float start = 0.25678;
  float result = 0.0;
  s21_from_float_to_decimal(start, &val);
  s21_from_decimal_to_float(val, &result);

  ck_assert_float_eq(round(start * 1000), round(result * 1000));
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *a = suite_create("Testing S21_FROM_FLOAT_TO_DECIMAL [Convertors]");
  TCase *test_1, *test_2, *test_3, *test_4, *test_5, *test_6;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_from_float_to_decimal_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_from_float_to_decimal_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_from_float_to_decimal_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_from_float_to_decimal_4);
  suite_add_tcase(a, test_4);

  test_5 = tcase_create("TEST5");
  tcase_add_test(test_5, s21_from_float_to_decimal_5);
  suite_add_tcase(a, test_5);

  test_6 = tcase_create("TEST6");
  tcase_add_test(test_6, s21_from_float_to_decimal_6);
  suite_add_tcase(a, test_6);

  return a;
}