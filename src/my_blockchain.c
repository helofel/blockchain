#include <stdint.h>
#include "stdio.h"
#include <stdlib.h>
#include "functions.c"

#include "my_blockchain.h"

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        struct Block *root = (struct Block *)malloc(sizeof(struct Block));
        root->block_header = (struct Header *)malloc(BLOCK_HEADER_SIZE * sizeof(struct Header));
        initializeHeader(root->block_header);
        root->next = NULL;
        // printf("%zu\n", root -> hash_ID);

        for (int index = 1; index < atoi(argv[1]); ++index)
        {
            // printf("%d\n", index + 1);
            addBlock(root);
        }

        toString(root);
        printf("Length: %d\n", blockchainLength(root));
        dismantle(root);
    }

    return 0;
}
