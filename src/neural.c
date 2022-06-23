#include "neural.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

neural* net_create(row_vector* config)
{
    // allocating memory to the pointer
    neural* net = malloc(sizeof(neural));
    // copying config input to the network
    net->config = row_vec_create(config->columns);
    memcpy(net->config->data, config->data, sizeof(float) * config->columns);
    // allocating memory to the matrixes
    net->layers = calloc(net->config->columns - 1, sizeof(matrix));

    // allocating memory for the matrix data
    for(int i = 0; i < net->config->columns - 1; ++i)
    {
        net->layers[i] = mat_create(round(net->config->data[i + 1]), round(net->config->data[i]));
    }

    return net;
}

void net_delete(neural* net)
{
    for(int i = 0; i < net->config->columns - 1; ++i)
    {
        free(net->layers[i]->data);
    }
    free(net->config);
    free(net->layers);
    free(net);
}

column_vector* net_process(neural* net1, column_vector* data)
{
    column_vector* result = mat_mul_vec(net1->layers[0], data);

    for(int i = 1; i < net1->config->columns - 1; ++i)
    {
        result = mat_mul_vec(net1->layers[i], result);
    }

    return result;
}

void net_fill_random(neural* net)
{
    for(int i = 0 ; i < net->config->columns - 1; ++i)
    {
        mat_fill_random(net->layers[i]);
    }
}
