#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

typedef struct {
  bool print_results_flag;
  bool print_time_flag;
  bool brute_force_flag;
  bool strassen_flag;
  bool combined_flag;
} Options;

typedef struct {
  int rows;
  int cols;
  float **data;
} Matrix;

typedef struct {
  Matrix (*multiply_func)(Matrix, Matrix, void *);
  void *extra_data;
} MultiplyFunction;

typedef struct {
  int num_matrices;
  Matrix *matrices;
  double *elapsed_times;
} MatrixArray;

typedef enum { PR, PT, B, S, C, INVALID } OptionType;

Matrix *add_matrix(Matrix *matrices, int index, int rows, int cols);

Matrix add_matrices(Matrix a, Matrix b);

Matrix combine_matrices(Matrix a, Matrix b, Matrix c, Matrix d);

MatrixArray create_empty_matrix_array();

void free_matrix(Matrix *matrix);

void free_matrix_array(MatrixArray *matrix_array);

void free_multiple_matrices(int count, ...);

MatrixArray initialize_matrix_array();

Matrix subtract_matrices(Matrix a, Matrix b);

Matrix multiply_matrix_pair(Matrix a, Matrix b,
                            MultiplyFunction multiply_function);

MatrixArray multiply_matrix_array(MatrixArray input,
                                  MultiplyFunction multiply_function);

void subdivide_matrix(Matrix matrix, Matrix *a, Matrix *b, Matrix *c,
                      Matrix *d);

void free_strassen_matrices(Matrix *p1, Matrix *p2, Matrix *p3, Matrix *p4,
                            Matrix *p5, Matrix *p6, Matrix *p7, Matrix *c11,
                            Matrix *c12, Matrix *c21, Matrix *c22, Matrix *a11,
                            Matrix *a12, Matrix *a21, Matrix *a22, Matrix *b11,
                            Matrix *b12, Matrix *b21, Matrix *b22);

#endif // MATRIX_H
