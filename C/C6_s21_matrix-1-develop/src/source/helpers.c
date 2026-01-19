#include "../s21_matrix.h"

int is_matrix(matrix_t *A) {
  int status = 0;
  if (A->rows > 0 && A->columns > 0 && A->matrix) status = 1;
  return status;
}

int is_square(matrix_t *A) {
  int status = 0;
  if (A->columns == A->rows) status = 1;
  return status;
}
