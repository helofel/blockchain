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
