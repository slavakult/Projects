#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_mul_1) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  float a = 9403.0e2;
  int b = 202;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = 189940600;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = 1234;
  int b = 10;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = 12340;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = 1234;
  int b = 10;
  int res_our_dec = 0;
  s21_from_int_to_decimal(b, &src1);
  s21_from_int_to_decimal(c, &src2);
  float res_origin = 12340;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 9403e2;
  int b = 1;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  long int res_origin = 940300;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_5) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 256;
  int b = 65536;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 16777216;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 256;
  int b = 65536;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 16777216;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 0;
  int b = 65536;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 0;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

Suite *suite_mul(void) {
  Suite *a = suite_create("Testing S21_MUL [Arithmetic]");
  TCase *test_1, *test_2, *test_3, *test_4, *test_5, *test_6, *test_7;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_mul_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_mul_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_mul_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_mul_4);
  suite_add_tcase(a, test_4);

  test_5 = tcase_create("TEST5");
  tcase_add_test(test_5, s21_mul_5);
  suite_add_tcase(a, test_5);

  test_6 = tcase_create("TEST6");
  tcase_add_test(test_6, s21_mul_6);
  suite_add_tcase(a, test_6);

  test_7 = tcase_create("TEST7");
  tcase_add_test(test_7, s21_mul_7);
  suite_add_tcase(a, test_7);

  return a;
}
