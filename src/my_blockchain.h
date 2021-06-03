#ifndef MY_BLOCKCHAIN_H
#define MY_BLOCKCHAIN_H

#define BLOCK_SIZE 4
#define BLOCK_HEADER_SIZE 32
#define KEY "184348917474414977452"


struct Block {
    // int32_t block_size;
    //unsigned long hash_ID; 
    char* message; 
    struct Header* block_header;
    struct Block* next;
};

struct Header {
    int32_t version; //a version number to track software/protocol upgrades [4] bytes
    void * previous_block_hash; //a reference to the hash of the previous (parent) block in the chain [32] bytes
    void *  merkle_root; //a hash of the root of the merkle tree of this block's transactions [32] bytes
    int32_t timestamp; //the appropriate creation time of this block(seconds from unix epoch) [4] bytes
    int32_t difficulty_target; //the proof-of-work algorithm difficulty target for this block [4] bytes
    int32_t nonce; //counter used for the proof-of-work algorithm [4] bytes
};

void addBlock(struct Block *); 
void dismantle(struct Block *);
int blockchainLength(struct Block *);
void initializeHeader(struct Header *);
void toString(struct Block *);
void reverse(char[], int);
void swap(char *, char *);
char* itoa(int, char*, int);

#endif
