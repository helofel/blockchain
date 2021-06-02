#include <stdint.h>
#include <unistd.h> //read() write()
#include "stdio.h"
#include <stdlib.h>
#include "string.h"
#include <stdbool.h>
#include "my_blockchain.h"
#include "sha256.c" 

void addBlock(struct Block *root)
{
    if (root->next == NULL)
    {
        root->next = (struct Block *)malloc(sizeof(struct Block));
        root->next->block_header = (struct Header *)malloc(sizeof(struct Header));
        initializeHeader(root->next->block_header);
        root->next->next = NULL;
        return;
    }
    addBlock(root->next);
}

void dismantle(struct Block *block)
{
    if (block == NULL)
        return;
    dismantle(block->next);

    free(block);
}

int blockchainLength(struct Block *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + blockchainLength(root->next);
}

void initializeHeader(struct Header *block_header)
{
    block_header->version = __STDC_VERSION__;
    block_header->previous_block_hash = (void *)malloc(sizeof(void));
    block_header->merkle_root = (void *)malloc(sizeof(void));
    block_header->timestamp = 0; 
    block_header->difficulty_target = 0;
    block_header->nonce = 0;
}


void toString(struct Block *root) //this may be causing a seg fault
{
    char string[21] = "";

    if (root == NULL)
    {
        return;
    }

    toString(root->next);
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        swap(&str[start++], &str[end--]);
    }
}

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

char *itoa(int num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}