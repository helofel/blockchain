#ifndef MY_BLOCKCHAIN_H
#define MY_BLOCKCHAIN_H

struct Block {
    int32_t block_size;
    struct Header* block_header;
    struct Block* previousBlock;
    struct Block* nextBlock;
};

struct Header {
    int32_t version; //a version number to track software/protocol upgrades [4] bytes
    void * previous_block_hash; //a reference to the hash ot the previous (parent) block in the chain [32] bytes
    void *  merkle_root; //a hash of the root of the merkle tree of this block's transactions [32] bytes
    int32_t timestamp; //the appropriate creation time of this block(seconds from unix epoch) [4] bytes
    int32_t difficulty_target; //the prof-of-work algorithm difficulty target for this block [4] bytes
    int32_t nonce; //counter used for the proof-of-work algorithm [4] bytes
};

#endif
