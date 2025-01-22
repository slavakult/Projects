#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 0;
  int equal = 1;
  if (is_matrix(A) && is_matrix(B) && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows && equal; i++) {
      for (int j = 0; j < A->columns && equal; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) equal = 0;
      }
    }
    status = equal;
  }
  return status;
}