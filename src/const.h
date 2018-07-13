//
// Created by ahmad on 6/3/18.
//

#ifndef BITCOIN_ENCRYPTION_CONST_H
#define BITCOIN_ENCRYPTION_CONST_H

// General Definitions
#define CHAR_SIZE_BIT 8

// Definition for padding and parsing
#define MAX_MESSAGE_SIZE 1024
#define MAX_PAYLOAD_BLOCK_SIZE_BYTE 56
#define PAD_PARSE_BLOCK_SIZE 512
#define LENGHT_PART_LEN_BIT 64
#define MAX_MESSAGE_BLOCK_COUNT 4

// Definition for expansion
#define EXPANSION_BLOCK_SIZE 32
#define EXPANSION_BLOCK_COUNT_IN_SET 64
#define EXPANSION_CHUNK_NUM 16


// Definition for compression
#define HASH_OUTPUT_SIZE 256
#define HASH_OUTPUT_SEGMENT_SIZE 32


#define XILINIX_SDK

#endif //BITCOIN_ENCRYPTION_CONST_H
