#include "test.h"

START_TEST(sum_matrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] + mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(casual_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t orig = {0};
  matrix_t result;
  int err1 = s21_create_matrix(3, 3, &A);
  int err2 = s21_create_matrix(3, 3, &B);
  int err3 = s21_create_matrix(3, 3, &orig);
  if (!err1 && !err2 && !err3) {
    A.matrix[0][0] = B.matrix[0][0] = 1;
    A.matrix[0][1] = B.matrix[0][1] = 2;
    A.matrix[0][2] = B.matrix[0][2] = 3;
    A.matrix[1][0] = B.matrix[1][0] = 4;
    A.matrix[1][1] = B.matrix[1][1] = 5;
    A.matrix[1][2] = B.matrix[1][2] = 6;
    A.matrix[2][0] = B.matrix[2][0] = 7;
    A.matrix[2][1] = B.matrix[2][1] = 8;
    A.matrix[2][2] = B.matrix[2][2] = 9;
    orig.matrix[0][0] = 2;
    orig.matrix[0][1] = 4;
    orig.matrix[0][2] = 6;
    orig.matrix[1][0] = 8;
    orig.matrix[1][1] = 10;
    orig.matrix[1][2] = 12;
    orig.matrix[2][0] = 14;
    orig.matrix[2][1] = 16;
    orig.matrix[2][2] = 18;
    int status = s21_sum_matrix(&A, &B, &result);
    int eq = s21_eq_matrix(&result, &orig);
    ck_assert_int_eq(0, status);
    ck_assert_int_eq(1, eq);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&orig);
    if (!status) s21_remove_matrix(&result);
  }
}

Suite *suite_sum(void) {
  Suite *s = suite_create("suite_sum_matrix");
  TCase *tc = tcase_create("case_sum_matrix");

  tcase_add_loop_test(tc, sum_matrix, 0, 100);
  tcase_add_loop_test(tc, sum_matrix2, 0, 100);

  tcase_add_test(tc, casual_matrix_1);

  suite_add_tcase(s, tc);
  return s;
}