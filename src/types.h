//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_TYPES_H
#define BITCOIN_ENCRYPTION_TYPES_H

#include <bitset>
#include "const.h"

// Pad-Parse phase types
using PadParseMessageBlock =  std::bitset<PAD_PARSE_BLOCK_SIZE>;
using ByteBitSet = std::bitset<CHAR_SIZE_BIT>;

// Expansion phase types
using ExpansionBlock = std::bitset<EXPANSION_BLOCK_SIZE>;

// Compression phase types
using HashBlock = std::bitset<HASH_OUTPUT_SIZE>;

#endif //BITCOIN_ENCRYPTION_TYPES_H
