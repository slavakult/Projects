#include "test.h"

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int err = s21_create_matrix(1, 1, &m);
  if (!err) {
    int status = s21_calc_complements(&m, &result);
    ck_assert_int_eq(status, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int status = s21_calc_complements(&m, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_not_square) {
  matrix_t m = {0};
  matrix_t result = {0};
  int err = s21_create_matrix(3, 4, &m);
  if (!err) {
    int status = s21_calc_complements(&m, &result);
    ck_assert_int_eq(status, CALC_ERROR);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_normal) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int err1 = s21_create_matrix(3, 3, &m);
  int err2 = s21_create_matrix(3, 3, &expected);
  if (!err1 && !err2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int status = s21_calc_complements(&m, &result);
    int eq = s21_eq_matrix(&result, &expected);

    ck_assert_int_eq(eq, SUCCESS);
    ck_assert_int_eq(status, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("calc_complements");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_not_square);
  tcase_add_test(tc, test_incorrect);
  tcase_add_test(tc, test_one_by_one);

  suite_add_tcase(s, tc);
  return s;
}