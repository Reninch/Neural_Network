#include <stdio.h>
#include <stdlib.h>

#include "neural.h"
#include "matrix.h"
#include "vector.h"

int main()
{
    row_vector* conf = row_vec_create(3);
    conf->data[0] = 2;
    conf->data[1] = 3;
    conf->data[2] = 1;

    column_vector* vec1 = column_vec_create(2);
    vec1->data[0] = 1.0f;
    vec1->data[1] = 100000.0f;
    
    neural* net = net_create(conf);

    net_fill_random(net);

    column_vector_print(net_process(net, vec1));

    return 0;
}
