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

// Creates a new column vector
column_vector* column_vec_create(int ROWS);
// Creates a new row vector
row_vector* row_vec_create(int COLUMNS);

// Deletes a row vector
void row_vec_delete(row_vector* vec);
// Deletes a column vector
void column_vec_delete(column_vector* vec);

// Adds two row vectors element by elemet
row_vector* row_vec_add(row_vector* vec1, row_vector* vec2);
// Adds two column vectors element by elemet
column_vector* column_vec_add(column_vector* vec1, column_vector* vec2);

// Subtracts two row vectors element by elemet
row_vector* row_vec_sub(row_vector* vec1, row_vector* vec2);
// Subtracts two column vectors element by elemet
column_vector* column_vec_sub(column_vector* vec1, column_vector* vec2);

// Multiplying row and column vector and returns float
float vec_mul(row_vector* vec1, column_vector* vec2);

// Prints row vector to stdout
void row_vector_print(row_vector* vec1);
// Prints column vector to stdout
void column_vector_print(column_vector* vec1);

// Loads from file row vector
row_vector* row_vec_load_from_file(char* filepath);
// Loads from file column vector
column_vector* column_vec_load_from_file(char* filepath);

// Saves row vector to file
void row_vec_save_to_file(row_vector* vec1, char* filepath);
// Saves column vector to file
void column_vec_save_to_file(column_vector* vec1, char* filepath);

#endif
