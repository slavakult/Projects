#include "../s21_decimal.h"
#include "s21_main_test.h"

START_TEST(s21_add_1) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = -1234;
  int b = 20;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = -1214;
  s21_add(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int c = 1234;
  int b = 20000;
  int res_our_dec = 0;
  s21_from_int_to_decimal(c, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = 21234;
  s21_add(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  float a = -1234.0;
  float b = 1.23;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = -1232.77;
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);

  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  float a = -1234.0;
  float b = -1.23;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = -1235.23;
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);

  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_5) {
  s21_decimal src1 = {0}, src2 = {0}, result = {0};
  int a = -1234;
  int b = -200;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1434;
  s21_add(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our_dec);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_6) {
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
  int res_our_dec = s21_add(src1, src2, &result);

  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal num1, num2, result, result2 = {0};
  num1.bits[0] = 0b11111111111111111111111111111111;
  num1.bits[1] = 0b11111111111111111111111111111111;
  num1.bits[2] = 0b11111111111111111111111111111111;
  num1.bits[3] = 0b00000000000000000000000000000000;

  num2.bits[0] = 0b00000000000000000000000000000001;
  num2.bits[1] = 0b00000000000000000000000000000000;
  num2.bits[2] = 0b00000000000000000000000000000000;
  num2.bits[3] = 0b00000000000000000000000000000000;

  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;

  int flag = s21_add(num1, num2, &result2);

  ck_assert_int_eq(flag, 1);
  ck_assert_int_eq(result.bits[0], result2.bits[0]);
  ck_assert_int_eq(result.bits[1], result2.bits[1]);
  ck_assert_int_eq(result.bits[2], result2.bits[2]);
  ck_assert_int_eq(result.bits[3], result2.bits[3]);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal num1, num2, result, result2 = {0};
  num1.bits[0] = 0b00000000000000000000000000000001;
  num1.bits[1] = 0b00000000000000000000000000000000;
  num1.bits[2] = 0b00000000000000000000000000000000;
  num1.bits[3] = 0b00000000000111110000000000000000;

  num2.bits[0] = 0b00000000000000000000000000000000;
  num2.bits[1] = 0b00000000000000000000000000000000;
  num2.bits[2] = 0b00000000000000000000000000000000;
  num2.bits[3] = 0b00000000000000000000000000000000;

  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;

  int flag = s21_add(num1, num2, &result2);

  ck_assert_int_eq(flag, 2);
  ck_assert_int_eq(result.bits[0], result2.bits[0]);
  ck_assert_int_eq(result.bits[1], result2.bits[1]);
  ck_assert_int_eq(result.bits[2], result2.bits[2]);
  ck_assert_int_eq(result.bits[3], result2.bits[3]);
}
END_TEST

START_TEST(s21_add_9) {
  s21_decimal val1 = {{100, 200, 300, 0x00050000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0, 0, 0x80060000}};
  s21_decimal res = {0};

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1001);
  ck_assert_int_eq(res.bits[1], 1999);
  ck_assert_int_eq(res.bits[2], 3000);
  ck_assert_int_eq(res.bits[3], 393216);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal val1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal res;

  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(s21_add_11) {
  s21_decimal val1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x80000000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal val1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x001C0000}};
  s21_decimal res;

  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(s21_add_13) {
  s21_decimal val1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x000D0000}};
  s21_decimal val2 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x000C0000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 3264175145);
  ck_assert_int_eq(res.bits[1], 2405181685);
  ck_assert_int_eq(res.bits[2], 472446402);
  ck_assert_int_eq(res.bits[3], 720896);
}
END_TEST

START_TEST(s21_add_14) {
  s21_decimal val1 = {{0, 0, 1, 0x00110000}};
  s21_decimal val2 = {{123456789, 0, 9876543, 0x00050000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1305451419);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 987654300);
  ck_assert_int_eq(res.bits[3], 458752);
}
END_TEST

START_TEST(s21_add_15) {
  s21_decimal val1 = {{0, 0, 1, 0x00110000}};
  s21_decimal val2 = {{123456789, 0, 9876543, 0x80050000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1911069901);
  ck_assert_int_eq(res.bits[1], 2);
  ck_assert_int_eq(res.bits[2], 987654300);
  ck_assert_int_eq(res.bits[3], 2147942400);
}
END_TEST

START_TEST(s21_add_16) {
  s21_decimal val1 = {{1, 2, 3, 0x801C0000}};
  s21_decimal val2 = {{11111111, 22222222, 33333333, 0x800A0000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 1111116634);
  ck_assert_int_eq(res.bits[1], 2222222200);
  ck_assert_int_eq(res.bits[2], 3333333300);
  ck_assert_int_eq(res.bits[3], 2148270080);
}
END_TEST

START_TEST(s21_add_17) {
  s21_decimal val1 = {{0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{5, 0, 0, 0x00010000}};
  s21_decimal res;

  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(s21_add_18) {
  s21_decimal val1 = {{387420489, 999999999, 123456789, 0x000E0000}};
  s21_decimal val2 = {{987654321, 666666666, 888888888, 0x80190000}};
  s21_decimal res;
  s21_add(val1, val2, &res);

  ck_assert_int_eq(2, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_19) {
  s21_decimal val1 = {{60, 0, 0, 0x80000000}};
  s21_decimal val2 = {{40, 0, 0, 0x80000000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 100);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0x80000000);
}
END_TEST

START_TEST(s21_add_20) {
  s21_decimal val1 = {{123, 456, 789, 0x800D0000}};
  s21_decimal val2 = {{111, 222, 333, 0x00100000}};
  s21_decimal res;

  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], 122889);
  ck_assert_int_eq(res.bits[1], 455778);
  ck_assert_int_eq(res.bits[2], 788667);
  ck_assert_int_eq(res.bits[3], 2148532224);
}
END_TEST

Suite *suite_add(void) {
  Suite *a = suite_create("Testing S21_ADD [Arithmetic]");
  TCase *test_1, *test_2, *test_3, *test_4, *test_5, *test_6, *test_7, *test_8,
      *test_9, *test_10, *test_11, *test_12, *test_13, *test_14, *test_15,
      *test_16, *test_17, *test_18, *test_19, *test_20;

  test_1 = tcase_create("TEST1");
  tcase_add_test(test_1, s21_add_1);
  suite_add_tcase(a, test_1);

  test_2 = tcase_create("TEST2");
  tcase_add_test(test_2, s21_add_2);
  suite_add_tcase(a, test_2);

  test_3 = tcase_create("TEST3");
  tcase_add_test(test_3, s21_add_3);
  suite_add_tcase(a, test_3);

  test_4 = tcase_create("TEST4");
  tcase_add_test(test_4, s21_add_4);
  suite_add_tcase(a, test_4);

  test_5 = tcase_create("TEST5");
  tcase_add_test(test_5, s21_add_5);
  suite_add_tcase(a, test_5);

  test_6 = tcase_create("TEST6");
  tcase_add_test(test_6, s21_add_6);
  suite_add_tcase(a, test_6);

  test_7 = tcase_create("TEST7");
  tcase_add_test(test_7, s21_add_7);
  suite_add_tcase(a, test_7);

  test_8 = tcase_create("TEST8");
  tcase_add_test(test_8, s21_add_8);
  suite_add_tcase(a, test_8);

  test_9 = tcase_create("TEST9");
  tcase_add_test(test_9, s21_add_9);
  suite_add_tcase(a, test_9);

  test_10 = tcase_create("TEST10");
  tcase_add_test(test_10, s21_add_10);
  suite_add_tcase(a, test_10);

  test_11 = tcase_create("TEST11");
  tcase_add_test(test_11, s21_add_11);
  suite_add_tcase(a, test_11);

  test_12 = tcase_create("TEST12");
  tcase_add_test(test_12, s21_add_12);
  suite_add_tcase(a, test_12);

  test_13 = tcase_create("TEST13");
  tcase_add_test(test_13, s21_add_13);
  suite_add_tcase(a, test_13);

  test_14 = tcase_create("TEST14");
  tcase_add_test(test_14, s21_add_14);
  suite_add_tcase(a, test_14);

  test_15 = tcase_create("TEST15");
  tcase_add_test(test_15, s21_add_15);
  suite_add_tcase(a, test_15);

  test_16 = tcase_create("TEST16");
  tcase_add_test(test_16, s21_add_16);
  suite_add_tcase(a, test_16);

  test_17 = tcase_create("TEST17");
  tcase_add_test(test_17, s21_add_17);
  suite_add_tcase(a, test_17);

  test_18 = tcase_create("TEST18");
  tcase_add_test(test_18, s21_add_18);
  suite_add_tcase(a, test_18);

  test_19 = tcase_create("TEST19");
  tcase_add_test(test_19, s21_add_19);
  suite_add_tcase(a, test_19);

  test_20 = tcase_create("TEST20");
  tcase_add_test(test_20, s21_add_20);
  suite_add_tcase(a, test_20);

  return a;
}
