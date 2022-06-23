#ifndef NEURAL_HEADER_GUARD

#include "vector.h"
#include "matrix.h"

#define NEURAL_HEADER_GUARD

typedef struct 
{
    row_vector* config;
    matrix** layers;
} neural;

neural* net_create(row_vector* config);
void net_delete(neural* net);

column_vector* net_process(neural* net1, column_vector* data);

void net_fill_random(neural* net);

void net_save_to_file(neural* net, char* filepath);
neural* net_open_from_file(char* filepath);

#endif
