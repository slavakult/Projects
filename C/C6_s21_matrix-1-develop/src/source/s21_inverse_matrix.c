#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = 0;
  double determinant = 0;
  matrix_t minor_tmp = {0};
  if (!is_matrix(A) || !(result)) {
    status = 1;
  } else if (!is_square(A) || s21_determinant(A, &determinant) ||
             !determinant) {
    status = 2;
  } else if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1. / determinant;
  } else {
    s21_calc_complements(A, &minor_tmp);
    s21_transpose(&minor_tmp, result);
    for (int i = 0; i < minor_tmp.rows; i++) {
      for (int j = 0; j < minor_tmp.columns; j++)
        result->matrix[i][j] /= determinant;
    }
    s21_remove_matrix(&minor_tmp);
  }
  return status;
}
