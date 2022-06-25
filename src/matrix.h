#ifndef MATRIX_HEADER_GUARD
#include "vector.h"
#define MATRIX_HEADER_GUARD

typedef struct 
{
    int rows;
    int columns;
    float* data;
} matrix;

// Returns a float between -1.0 and 1.0
float rand_norm();

// Creates a new matrix with specified rows and columns and returns a pointer to it
matrix* mat_create(int ROWS, int COLUMNS);

// Deletes a matrix
void mat_delete(matrix* mat1);

// Adds matrices with equal size
matrix* mat_add(matrix* mat1, matrix* mat2);

// Subtract matrices with equal size
matrix* mat_sub(matrix* mat1, matrix* mat2);

// Multiplies matrices(even with not equal size)
matrix* mat_mul(matrix* mat1, matrix* mat2);

// Multiplies row vector by matrix and returns a pointer to row vector
row_vector* vec_mul_mat(row_vector* vec2, matrix* mat1);

// Multiplies matrix by column vector and returns a pointer to the column vector
column_vector* mat_mul_vec(matrix* mat1, column_vector* vec2);

// Returns a row vector from a matrix
row_vector* mat_get_row(matrix* mat1, int ROW);

// Returns a column vector from a matrix
column_vector* mat_get_column(matrix* mat1, int COLUMN);

// Prints matrix to stdout
void mat_print(matrix* mat1);

// Fills elements from matrix with random values via rand_norm function
void mat_fill_random(matrix* mat1);

// Loads from file system a matrix binary file
matrix* mat_load_from_file(char* file_path);

// Saves to binary file a matrix
void mat_save_to_file(matrix* mat1, char* file_path);

#endif
