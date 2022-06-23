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
    result->rows = ROWS;
    result->columns = COLUMNS;
    result->data = calloc(ROWS * COLUMNS, sizeof(float));
    return result;
}

void mat_delete(matrix* mat1)
{
    free(mat1->data);
    free(mat1);
}

matrix* mat_add(matrix* mat1, matrix* mat2)
{
    matrix* result = mat_create(mat2->rows, mat1->columns);
    for(int i = 0; i < mat1->columns * mat2->rows; ++i)
        result->data[i] = mat1->data[i] + mat2->data[i];
    return result;
}

matrix* mat_sub(matrix* mat1, matrix* mat2)
{
    matrix* result = mat_create(mat2->rows, mat1->columns);
    for(int i = 0; i < mat1->columns * mat2->rows; ++i)
        result->data[i] = mat1->data[i] - mat2->data[i];
    return result;
}

matrix* mat_mul(matrix* mat1, matrix* mat2)
{
    matrix* result = mat_create(mat1->rows, mat2->columns);

    
    
    return result;
}

row_vector* vec_mul_mat(row_vector* vec2, matrix* mat1)
{
    row_vector* result = row_vec_create(vec2->columns);

    for(int i = 0; i < vec2->columns; ++i)
    {
        result->data[i] = vec_mul(vec2, mat_get_column(mat1, i));
    }
    return result;
}

column_vector* mat_mul_vec(matrix* mat1, column_vector* vec2)
{
    column_vector* result = column_vec_create(mat1->rows); 
    
    for(int i = 0; i < mat1->columns; ++i)
    {
        result->data[i] = vec_mul(mat_get_row(mat1, i),vec2);
    }
    return result;
}

row_vector* mat_get_row(matrix* mat1, int ROW)
{
    row_vector* result = row_vec_create(mat1->columns);
    for(int i = 0; i < mat1->columns; ++i)
    {
        result->data[i] = mat1->data[mat1->columns * ROW + i];
    }
    return result;
}

column_vector* mat_get_column(matrix* mat1, int COLUMN)
{
    column_vector* result = column_vec_create(mat1->rows);
    for(int i = 0; i < mat1->columns; ++i)
    {
        result->data[i] = mat1->data[mat1->columns * i + COLUMN];
    }
    return result;
}

void mat_print(matrix* mat1)
{
    // row
    for(int i = 0; i < mat1->rows; ++i)
    {
        // column
        printf("{");
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
    
    for(int i = 0; i < mat1->columns * mat1->rows; ++i)
        mat1->data[i] = rand_norm();
}

matrix* mat_load_from_file(char* file_path)
{
    matrix* mat1 = malloc(sizeof(matrix));
    FILE* file = fopen(file_path, "rb");
    fread(mat1, sizeof(matrix), 1, file);
    fread(mat1->data, sizeof(float), mat1->columns * mat1->rows, file);
    fclose(file);
    return mat1;
}

void mat_save_to_file(matrix* mat1, char* file_path)
{
    FILE* file = fopen(file_path, "wb");
    fwrite(mat1, sizeof(matrix), 1, file);
    fwrite(mat1->data, sizeof(float), mat1->columns * mat1->rows, file);
    fclose(file);
}
