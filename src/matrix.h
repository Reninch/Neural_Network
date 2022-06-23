#ifndef MATRIX_HEADER_GUARD
#include "vector.h"
#define MATRIX_HEADER_GUARD

typedef struct 
{
    int rows;
    int columns;
    float* data;
} matrix;

float rand_norm();

matrix* mat_create(int ROWS, int COLUMNS);
void mat_delete(matrix* mat1);

matrix* mat_add(matrix* mat1, matrix* mat2);
matrix* mat_sub(matrix* mat1, matrix* mat2);
matrix* mat_mul(matrix* mat1, matrix* mat2);

row_vector* vec_mul_mat(row_vector* vec2, matrix* mat1);
column_vector* mat_mul_vec(matrix* mat1, column_vector* vec2);

row_vector* mat_get_row(matrix* mat1, int ROW);
column_vector* mat_get_column(matrix* mat1, int COLUMN);

void mat_print(matrix* mat1);
void mat_fill_random(matrix* mat1);

matrix* mat_load_from_file(char* file_path);
void mat_save_to_file(matrix* mat1, char* file_path);

#endif
