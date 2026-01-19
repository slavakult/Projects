#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_div_1) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  float a = 9400;
  int b = 20;
  int res_our_dec = 0.0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 470;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = 1235;
  int b = 5;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 247;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = -1250;
  int b = 50;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = -25;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 9403e2;
  int b = 1;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  long int res_origin = 940300;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 256;
  int b = 2560;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 0.1;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 2560;
  int b = -256;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -10;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_7) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000111000000000000000000;

  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int res_origin = 0;
  int res_our_dec = s21_div(src1, src2, &result);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 0;
  int b = 256;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 0;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_9) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 256;
  int b = 0;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 0;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_10) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = 1;
  int b = 2560;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = 0;
  s21_div(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

Suite *suite_div(void) {
  Suite *a = suite_create("Testing S21_DIV [Arithmetic]");
  TCase *test_1, *test_2, *test_3, *test_4, *test_5, *test_6, *test_7, *test_8,
      *test_9, *test_10;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_div_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_div_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_div_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_div_4);
  suite_add_tcase(a, test_4);

  test_5 = tcase_create("TEST5");
  tcase_add_test(test_5, s21_div_5);
  suite_add_tcase(a, test_5);

  test_6 = tcase_create("TEST6");
  tcase_add_test(test_6, s21_div_6);
  suite_add_tcase(a, test_6);

  test_7 = tcase_create("TEST7");
  tcase_add_test(test_7, s21_div_7);
  suite_add_tcase(a, test_7);

  test_8 = tcase_create("TEST8");
  tcase_add_test(test_8, s21_div_8);
  suite_add_tcase(a, test_8);

  test_9 = tcase_create("TEST9");
  tcase_add_test(test_9, s21_div_9);
  suite_add_tcase(a, test_9);

  test_10 = tcase_create("TEST10");
  tcase_add_test(test_10, s21_div_10);
  suite_add_tcase(a, test_10);

  return a;
}