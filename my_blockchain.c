#include <stdint.h>
#include "stdio.h"
#include <stdlib.h>
#include "functions.c"

#include "my_blockchain.h"

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        struct Block *root = (struct Block *)malloc(sizeof(struct Block));
        // root->block_size = (int32_t)malloc(BLOCK_SIZE);
        root->block_header = (struct Header *)malloc(BLOCK_HEADER_SIZE * sizeof(struct Header));
        // root->next = (struct Block *)malloc(sizeof(struct Block));
        root -> next = NULL;

        for (int index = 0; index < argv[1][0]; ++index)
        {
            addBlock(root); 
        }
    }
    return 0;
}
