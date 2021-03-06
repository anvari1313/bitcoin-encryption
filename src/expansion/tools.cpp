//
// Created by ahmad on 6/5/18.
//

#include "tools.h"
#include <string>
#include <sstream>
#include <iostream>

ExpansionBlock rot(unsigned int n, ExpansionBlock x)
{
    ExpansionBlock rotated = (x >> n) | (x << EXPANSION_BLOCK_SIZE - n);

    return rotated;
}

ExpansionBlock shf(unsigned int n, ExpansionBlock x)
{
    ExpansionBlock shifted = x >> n;

    return shifted;
}


ExpansionBlock permutationBox(ExpansionBlock block) {
    ExpansionBlock result;
    int i = 0;
    for ( ; i < EXPANSION_BLOCK_SIZE / 2; i++) {
        result[i] = block[EXPANSION_BLOCK_SIZE- i - 1];
    }

    for ( ; i < (EXPANSION_BLOCK_SIZE / 4) * 3; i++) {
        result[i] = block[i - 8];
    }

    for ( ; i < EXPANSION_BLOCK_SIZE; i++) {
        result[i] = block[EXPANSION_BLOCK_SIZE - i - 1];
    }

    return result;
}

#ifndef XILINIX_SDK
std::string HashBlockToString(HashBlock block) {
    std::string output;
    std::stringstream stream(block.to_string());
    char c;
    while(stream.good()) {
        std::bitset<8> bits;
        stream >> bits;
        c = char(bits.to_ulong());
        output += c;
    }

    return output;
}

std::string hashBlockToHex(HashBlock block) {
    ByteBitSet c;
    std::stringstream stream;

    for (int i = 0; i < HASH_OUTPUT_SEGMENT_SIZE * 2; i++) {
        for (int j = 0; j < CHAR_SIZE_BIT / 2; j++) {
            c[(CHAR_SIZE_BIT / 2) - 1 - j] = block[HASH_OUTPUT_SIZE - 1 - (i * CHAR_SIZE_BIT / 2) - j];
        }

        stream << std::hex << c.to_ulong();

    }


    return stream.str();
}

std::string expansionBlockToHex(ExpansionBlock block) {
    ByteBitSet c;
    std::stringstream stream;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < CHAR_SIZE_BIT / 2; j++) {
            c[(CHAR_SIZE_BIT / 2 ) - 1 - j] = block[EXPANSION_BLOCK_SIZE - 1 - (i * CHAR_SIZE_BIT / 2) - j];
        }

        stream << std::hex << c.to_ulong();

    }

    return stream.str();
}
#endif