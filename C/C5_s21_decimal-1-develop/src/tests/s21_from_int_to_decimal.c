#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_from_int_to_decimal_1) {
  s21_decimal dec1 = {0};
  int result = 256;
  int second = 0;

  s21_from_int_to_decimal(result, &dec1);
  s21_from_decimal_to_int(dec1, &second);

  ck_assert_int_eq(second, result);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  s21_decimal dec1 = {0};
  int result = -256;
  int second = 0;

  s21_from_int_to_decimal(result, &dec1);
  s21_from_decimal_to_int(dec1, &second);

  ck_assert_int_eq(second, result);
}
END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *a = suite_create("Testing S21_FROM_INT_TO_DECIMAL [Convertors]");
  TCase *test_1, *test_2;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_from_int_to_decimal_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_from_int_to_decimal_2);
  suite_add_tcase(a, test_2);

  return a;
}