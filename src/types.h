//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_TYPES_H
#define BITCOIN_ENCRYPTION_TYPES_H

#include <bitset>
#include "const.h"

// Pad-Parse phase types
typedef std::bitset<PAD_PARSE_BLOCK_SIZE>   PadParseMessageBlock;
typedef std::bitset<CHAR_SIZE_BIT>          ByteBitSet;

// Expansion phase types
typedef std::bitset<EXPANSION_BLOCK_SIZE>     ExpansionBlock;
//using ExpansionBlockSet = ExpansionBlock[EXPANSION_BLOCK_COUNT_IN_SET];
typedef std::vector<ExpansionBlock> ExpansionBlockVec;

// Compression phase types
typedef std::bitset<HASH_OUTPUT_SIZE> HashBlock;
typedef std::bitset<HASH_OUTPUT_SEGMENT_SIZE> HashBlockSegment;
typedef unsigned long int Prime;

#endif //BITCOIN_ENCRYPTION_TYPES_H
