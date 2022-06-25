#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

column_vector* column_vec_create(int ROWS)
{
    
    column_vector* result = malloc(sizeof(column_vector));
    result->rows = ROWS;
    result->data = calloc(ROWS, sizeof(float));
    return result;
}

row_vector* row_vec_create(int COLUMNS)
{
    row_vector* result = malloc(sizeof(row_vector));
    result->columns = COLUMNS;
    result->data = calloc(COLUMNS, sizeof(float));
    return result;
}

void row_vec_delete(row_vector* vec)
{
    free(vec->data);
    free(vec);
}

void column_vec_delete(column_vector* vec)
{
    free(vec->data);
    free(vec);
}

row_vector* row_vec_add(row_vector* vec1, row_vector* vec2)
{
    row_vector* result = row_vec_create(vec1->columns);
    for(int i = 0; i < vec1->columns; ++i)
        result->data[i] = vec1->data[i] + vec2->data[i];
    return result;
}

column_vector* column_vec_add(column_vector* vec1, column_vector* vec2)
{
    column_vector* result = column_vec_create(vec1->rows);
    for(int i = 0; i < vec1->rows; ++i)
        result->data[i] = vec1->data[i] + vec2->data[i];
    return result;
}

row_vector* row_vec_sub(row_vector* vec1, row_vector* vec2)
{
    row_vector* result = row_vec_create(vec1->columns);
    for(int i = 0; i < vec1->columns; ++i)
        result->data[i] = vec1->data[i] - vec2->data[i];
    return result;
}

column_vector* column_vec_sub(column_vector* vec1, column_vector* vec2)
{
    column_vector* result = column_vec_create(vec1->rows);
    for(int i = 0; i < vec1->rows; ++i)
        result->data[i] = vec1->data[i] - vec2->data[i];
    return result;
}

float vec_mul(row_vector* vec1, column_vector* vec2)
{
    float result = 0.0f;
    for(int i = 0; i < vec1->columns; ++i)
        result += vec1->data[i] * vec2->data[i];
    return result;
}

void row_vector_print(row_vector* vec1)
{
    printf("{");
    for(int i = 0; i < vec1->columns; ++i)
    {
        printf("%f ", vec1->data[i]);
    }
    printf("}\n");
}

void column_vector_print(column_vector* vec1)
{
    for(int i = 0; i < vec1->rows; ++i)
    {
        printf("{");
        printf("%f ", vec1->data[i]);
        printf("}\n");
    }
}

row_vector* row_vec_load_from_file(char* filepath)
{
    row_vector* vec1 = malloc(sizeof(row_vector));
    FILE* file = fopen(filepath, "rb");
    fread(vec1, sizeof(row_vector), 1, file);
    fread(vec1->data, sizeof(float), vec1->columns, file);
    fclose(file);
    return vec1;
}

column_vector* column_vec_load_from_file(char* filepath)
{
    column_vector* vec1 = malloc(sizeof(column_vector));
    FILE* file = fopen(filepath, "rb");
    fread(vec1, sizeof(column_vector), 1, file);
    fread(vec1->data, sizeof(float), vec1->rows, file);
    fclose(file);
    return vec1;
}

void row_vec_save_to_file(row_vector* vec1, char* filepath)
{
    FILE* file = fopen(filepath, "wb");
    fwrite(vec1, sizeof(row_vector), 1, file);
    fwrite(vec1->data, sizeof(float), vec1->columns, file);

    fclose(file);
}

void column_vec_save_to_file(column_vector* vec1, char* filepath)
{
    FILE* file = fopen(filepath, "wb");
    fwrite(vec1, sizeof(column_vector), 1, file);
    fwrite(vec1->data, sizeof(float), vec1->rows, file);

    fclose(file);
}
