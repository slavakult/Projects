#include "test.h"

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int err = s21_create_matrix(1, 1, &m);
  if (!err) {
    m.matrix[0][0] = 5;
    int status = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(status, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_zero_det) {
  matrix_t m = {0};
  matrix_t result = {0};
  int err = s21_create_matrix(1, 1, &m);
  if (!err) {
    int status = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(status, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int status = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  int err = s21_create_matrix(1, 4, &m);
  if (!err) {
    int status = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(status, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(test_normal) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int err1 = 0, err2 = 0;
  err1 = s21_create_matrix(3, 3, &m);
  if (!err1) err2 = s21_create_matrix(3, 3, &expected);

  if (!err1 && !err2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int status = s21_inverse_matrix(&m, &result);
    int eq = s21_eq_matrix(&result, &expected);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);

    ck_assert_int_eq(eq, SUCCESS);
    ck_assert_int_eq(status, OK);
  }
}
END_TEST

START_TEST(test_normal_1) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int err1 = 0, err2 = 0;
  err1 = s21_create_matrix(3, 3, &m);
  if (!err1) err2 = s21_create_matrix(3, 3, &expected);

  if (!err1 && !err2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 4;
    m.matrix[0][2] = 0;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 4;
    m.matrix[2][1] = 8;
    m.matrix[2][2] = 4;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = -0.5;
    expected.matrix[0][2] = 0.25;

    expected.matrix[1][0] = 0.25;
    expected.matrix[1][1] = 0.25;
    expected.matrix[1][2] = -0.125;

    expected.matrix[2][0] = -0.5;
    expected.matrix[2][1] = 0;
    expected.matrix[2][2] = 0.25;
    matrix_t result = {0};
    int status = s21_inverse_matrix(&m, &result);
    int eq = s21_eq_matrix(&result, &expected);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);

    ck_assert_int_eq(eq, SUCCESS);
    ck_assert_int_eq(status, OK);
  }
}
END_TEST

Suite *suite_inverse(void) {
  Suite *s = suite_create("inverse_matrix");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_normal_1);
  tcase_add_test(tc, test_not_sqare);
  tcase_add_test(tc, test_zero_det);
  tcase_add_test(tc, test_incorrect);
  tcase_add_test(tc, test_one_by_one);

  suite_add_tcase(s, tc);
  return s;
}