#include "../s21_matrix.h"

void minor_matrix(matrix_t *A, matrix_t *result) {
  matrix_t tmp = {0};
  int size = A->rows;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (A->rows > 1) {
        s21_create_matrix(size - 1, size - 1, &tmp);
        get_matrix(A, &tmp, i, j, size);
        result->matrix[i][j] = simple_determinant(&tmp, size - 1);
        s21_remove_matrix(&tmp);
      } else {
        result->matrix[0][0] = simple_determinant(A, 1);
      }
    }
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (!is_matrix(A) || !(result)) {
    status = 1;
  } else if (!is_square(A)) {
    status = 2;
  } else {
    s21_create_matrix(A->rows, A->rows, result);
    minor_matrix(A, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = result->matrix[i][j] * pow(-1., i + j);
    }
  }
  return status;
}