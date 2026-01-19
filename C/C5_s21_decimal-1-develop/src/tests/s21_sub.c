#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_sub_1) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = -1234;
  int b = 20;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1254;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = 1234;
  int b = 20000;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -18766;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = -1234;
  int b = 34;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1268;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = -1234;
  int b = -34;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1200;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 461114412;
  int b = -12;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 461114424;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = -461114412;
  int b = -12;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -461114400;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

Suite *suite_sub(void) {
  Suite *a = suite_create("Testing S21_SUB [Arithmetic]");
  TCase *test_1, *test_2, *test_3, *test_4, *test_5, *test_6;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_sub_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_sub_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_sub_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_sub_4);
  suite_add_tcase(a, test_4);

  test_5 = tcase_create("TEST5");
  tcase_add_test(test_5, s21_sub_5);
  suite_add_tcase(a, test_5);

  test_6 = tcase_create("TEST6");
  tcase_add_test(test_6, s21_sub_6);
  suite_add_tcase(a, test_6);

  return a;
}
