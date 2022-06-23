#ifndef VECTOR_HEADER_GUARD
#define VECTOR_HEADER_GUARD

typedef struct 
{
    int columns;
    float* data;
} row_vector;

typedef struct 
{
    int rows;
    float* data;
} column_vector;

column_vector* column_vec_create(int ROWS);
row_vector* row_vec_create(int COLUMNS);

void row_vec_delete(row_vector* vec);
void column_vec_delete(column_vector* vec);

row_vector* row_vec_add(row_vector* vec1, row_vector* vec2);
column_vector* column_vec_add(column_vector* vec1, column_vector* vec2);

row_vector* row_vec_sub(row_vector* vec1, row_vector* vec2);
column_vector* column_vec_sub(column_vector* vec1, column_vector* vec2);

float vec_mul(row_vector* vec1, column_vector* vec2);

void row_vector_print(row_vector* vec1);
void column_vector_print(column_vector* vec1);

row_vector* row_vec_load_from_file(char* filepath);
column_vector* column_vec_load_from_file(char* filepath);

void row_vec_save_to_file(row_vector* vec1, char* filepath);
void column_vec_save_to_file(column_vector* vec1, char* filepath);

#endif
