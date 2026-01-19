#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_is_not_equal_1) {
  s21_decimal dst1 = {0}, dst2 = {0};

  s21_from_float_to_decimal(5.5, &dst1);
  s21_from_float_to_decimal(5.5, &dst2);

  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 0);
}
END_TEST

START_TEST(s21_is_not_equal_2) {
  s21_decimal dst1 = {0}, dst2 = {0};

  s21_from_int_to_decimal(2000000009, &dst1);
  s21_from_int_to_decimal(2000000000, &dst2);

  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 1);
}
END_TEST

START_TEST(s21_is_not_equal_3) {
  s21_decimal dst1 = {0}, dst2 = {0};

  s21_from_int_to_decimal(-200, &dst1);
  s21_from_int_to_decimal(-200, &dst2);

  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 0);
}
END_TEST

START_TEST(s21_is_not_equal_4) {
  s21_decimal dst1 = {0}, dst2 = {0};

  s21_from_int_to_decimal(200, &dst1);
  s21_from_int_to_decimal(-200, &dst2);

  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 1);
}
END_TEST

Suite *suite_is_not_equal(void) {
  Suite *a = suite_create("Testing S21_IS_NOT_EQUAL [Comparison]");
  TCase *test_1, *test_2, *test_3, *test_4;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_is_not_equal_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_is_not_equal_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_is_not_equal_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_is_not_equal_4);
  suite_add_tcase(a, test_4);

  return a;
}