#include "matrix.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


float rand_norm()
{
    return (((float)rand()) / ((float) RAND_MAX) * 2.0f - 1.0f);
}


matrix* mat_create(int ROWS, int COLUMNS)
{
    matrix* result = malloc(sizeof(matrix));
    // defines size of matrix
    result->rows = ROWS;
    result->columns = COLUMNS;
    // allocates memory for elements of matrix
    result->data = calloc(ROWS * COLUMNS, sizeof(float));
    
    return result;
}

// 
void mat_delete(matrix* mat1)
{
    // frees elements of matrix
    free(mat1->data);
    // frees matrix
    free(mat1);
    // nullifies pointer
    mat1 = (void*) 0;
}

matrix* mat_add(matrix* mat1, matrix* mat2)
{
    matrix* result = mat_create(mat2->rows, mat1->columns);

    // iterating through both matrixes and adds element by element
    for(int i = 0; i < mat1->columns * mat2->rows; ++i)
        result->data[i] = mat1->data[i] + mat2->data[i];
    
    return result;
}

matrix* mat_sub(matrix* mat1, matrix* mat2)
{
    matrix* result = mat_create(mat2->rows, mat1->columns);

    // iterating through both matrixes and subtracts element by element
    for(int i = 0; i < mat1->columns * mat2->rows; ++i)
        result->data[i] = mat1->data[i] - mat2->data[i];

    return result;
}

matrix* mat_mul(matrix* mat1, matrix* mat2)
{
    matrix* result = mat_create(mat1->rows, mat2->columns);

    // NOT IMPLEMENTED YET
    
    return result;
}

row_vector* vec_mul_mat(row_vector* vec2, matrix* mat1)
{
    row_vector* result = row_vec_create(vec2->columns);

    // iterating and multiplying matrix's columns by given row vector
    for(int i = 0; i < vec2->columns; ++i)
    {
        result->data[i] = vec_mul(vec2, mat_get_column(mat1, i));
    }

    return result;
}

column_vector* mat_mul_vec(matrix* mat1, column_vector* vec2)
{
    column_vector* result = column_vec_create(mat1->rows); 
    
    // iterating and multiplying matrix's rows by given column vector
    for(int i = 0; i < mat1->columns; ++i)
    {
        result->data[i] = vec_mul(mat_get_row(mat1, i),vec2);
    }
    return result;
}

row_vector* mat_get_row(matrix* mat1, int ROW)
{
    row_vector* result = row_vec_create(mat1->columns);
    // adding elements from matrix to result vector
    for(int i = 0; i < mat1->columns; ++i)
    {
        result->data[i] = mat1->data[mat1->columns * ROW + i];
    }
    return result;
}

column_vector* mat_get_column(matrix* mat1, int COLUMN)
{
    column_vector* result = column_vec_create(mat1->rows);
    // adding elements from matrix to result vector
    for(int i = 0; i < mat1->columns; ++i)
    {
        result->data[i] = mat1->data[mat1->columns * i + COLUMN];
    }
    return result;
}

void mat_print(matrix* mat1)
{
    // iterating through rows of matrix
    for(int i = 0; i < mat1->rows; ++i)
    {
        // iterating through columns of matrix
        printf("{");
        // printing all elements
        for(int j = 0; j < mat1->columns; ++j)
        {
            printf("%f ", mat1->data[mat1->columns * i + j]);
        }
        printf("}");
        printf("\n");
    }
}

void mat_fill_random(matrix* mat1)
{
    // iterates all elements of matrix and sets to a random value via rand_norm()
    for(int i = 0; i < mat1->columns * mat1->rows; ++i)
        mat1->data[i] = rand_norm();
}

matrix* mat_load_from_file(char* file_path)
{
    matrix* mat1 = malloc(sizeof(matrix));
    // opening file
    FILE* file = fopen(file_path, "rb");
    // reading matrix header and writing to mat1
    fread(mat1, sizeof(matrix), 1, file);
    // reading matrix contents and writing to mat1
    fread(mat1->data, sizeof(float), mat1->columns * mat1->rows, file);
    // closing file
    fclose(file);

    return mat1;
}

void mat_save_to_file(matrix* mat1, char* file_path)
{
    // opening a file
    FILE* file = fopen(file_path, "wb");
    // writing matrix header to the file
    fwrite(mat1, sizeof(matrix), 1, file);
    // writing content of matrix to the file
    fwrite(mat1->data, sizeof(float), mat1->columns * mat1->rows, file);
    // closing file
    fclose(file);
}
