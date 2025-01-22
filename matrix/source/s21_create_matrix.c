#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;
  if (rows > 0 && columns > 0 && result) {
    size_t size = rows * sizeof(double *) + rows * columns * sizeof(double);
    result->matrix = (double **)calloc(1, size);
    if (result->matrix) {
      double *data = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = data + columns * i;
      }
      result->rows = rows;
      result->columns = columns;
    } else {
      status = 1;
    }
  } else {
    status = 1;
  }
  return status;
}