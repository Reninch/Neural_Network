#ifndef NEURAL_HEADER_GUARD

#include "vector.h"
#include "matrix.h"

#define NEURAL_HEADER_GUARD

typedef struct 
{
    row_vector* config;
    matrix** layers;
} neural;

// Creates a new neural network
neural* net_create(row_vector* config);
// Deletes a neural network
void net_delete(neural* net);

// Processes data with neural network
column_vector* net_process(neural* net1, column_vector* data);

// Fills all matrices from network with random values 
void net_fill_random(neural* net);

// Saves network to file
void net_save_to_file(neral* net, char* filepath);
// Loads from file and returns a pointer to network
neural* net_open_from_file(char* filepath);

#endif
