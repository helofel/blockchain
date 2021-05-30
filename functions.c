#include "stdio.h"
#include <stdlib.h>
#include <time.h>>

#include "my_blockchain.h"

void addBlock(struct Block* root) {
    if(root == NULL){
        root -> next = (struct Block*)malloc(sizeof(struct Block));
        root -> next -> block_header = (struct Header *)malloc(sizeof(struct Header));
        initializeHeader(root -> next -> block_header);
        root -> next -> next = NULL;
        return;
    }
    addBlock(root ->next);
}

void initializeHeader(struct Header* block_header){
    block_header -> version = __STDC_VERSION__;
    block_header -> previous_block_hash = (void *)malloc(sizeof(void));
    block_header -> merkle_root = (void *)malloc(sizeof(void));
    block_header -> timestamp = (unsigned long)time(NULL);
    block_header -> difficulty_target = 0;
    block_header -> nonce = 0;

}