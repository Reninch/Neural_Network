# Neural Network
This project tries to implement Neural Networks, written in c.

## Current status:
In development.

## Implemented:
    Vectors
    Matrixes
    Neural Networks

## TODO:
 1. Activation functions
 2. Learning stuff
 2. Write documentation

## How to create new network:
 1. Create a row vector with configuration of network
row_vector* config = row_vec_create(3);
config->data[0] = 2.0;
config->data[1] = 3.0;
config->data[2] = 1.0;
 
 2. Create new network with config
    neural* net = net_create(config);
 
 3. (optional) fill weights with random values in range from -1.0 to 1.0
    net_fill_random(net);

 4. Train (Not done)
    net_train(net);

 5. Process data
    column_vector* data = column_vec_create(2);
    data->data[0] = 4.0;
    data->data[0] = 1.0;

    column_vector* result = column_vec_create(1);
    result = net_process(net, data);