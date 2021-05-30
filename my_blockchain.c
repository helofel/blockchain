#include <stdint.h>
#include "stdio.h"
#include <stdlib.h>

#include "my_blockchain.h"

int main(int argc, char** argv){

    struct Block * root = (struct Block *)malloc(sizeof(struct Block));
    root -> block_size = (int32_t)malloc(BLOCK_SIZE);
    root -> block_header = (struct Header *)malloc(BLOCK_HEADER_SIZE * sizeof(struct Header)); 
    root -> next = (struct Block *)malloc(sizeof(struct Block));

    return 0;
}
