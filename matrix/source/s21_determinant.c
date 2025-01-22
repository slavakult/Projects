#include <stdlib.h>

#include "../s21_matrix.h"

void get_matrix(matrix_t *A, matrix_t *tmp, int i, int j, int size) {
  int ki = 0, kj = 0, di = 0, dj = 0;
  for (ki = 0; ki < size - 1; ki++) {
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj < size - 1; kj++) {
      if (kj == j) dj = 1;
      tmp->matrix[ki][kj] = A->matrix[ki + di][kj + dj];
    }
  }
}

double simple_determinant(matrix_t *A, int size) {
  int k = 1;
  int n = size - 1;
  double determinant = 0;
  matrix_t tmp = {0};
  if (size == 1) {
    determinant = A->matrix[0][0];
  }
  if (size == 2) {
    determinant =
        A->matrix[0][0] * A->matrix[1][1] - (A->matrix[1][0] * A->matrix[0][1]);
  }
  if (size > 2) {
    s21_create_matrix(size, size, &tmp);
    for (int i = 0; i < size; i++) {
      get_matrix(A, &tmp, i, 0, size);
      determinant =
          determinant + k * A->matrix[i][0] * simple_determinant(&tmp, n);
      k = -k;
    }
    s21_remove_matrix(&tmp);
  }
  return determinant;
}

int s21_determinant(matrix_t *A, double *result) {
  int status = 0;
  if (!is_matrix(A) || !(result)) {
    status = 1;
  } else if (!is_square(A)) {
    status = 2;
  } else {
    *result = simple_determinant(A, A->rows);
  }
  return status;
}