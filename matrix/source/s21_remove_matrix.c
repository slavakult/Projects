#include <stdlib.h>

#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    int size = A->rows + A->rows * A->columns;
    for (int i = 0; i < size; i++) {
      A->matrix[i] = 0;
    }
    A->rows = 0;
    A->columns = 0;
    if (A->matrix) free(A->matrix);
    A->matrix = NULL;
  }
}