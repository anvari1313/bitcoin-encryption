//
// Created by ahmad on 6/5/18.
//

#include "tools.h"
#include <string>
#include <sstream>

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
    for (int i = 0; i < EXPANSION_BLOCK_SIZE; i++) {
        result[i] = block[EXPANSION_BLOCK_SIZE - 1 - i];
    }

    return result;
}

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

std::string HashBlockToHex(HashBlock block) {
    ByteBitSet c;
    std::stringstream stream;

    for (int i = 0; i < HASH_OUTPUT_SEGMENT_SIZE; i++) {
        for (int j = 0; j < CHAR_SIZE_BIT; j++) {
            c[CHAR_SIZE_BIT - 1 - j] = block[HASH_OUTPUT_SIZE - 1 - (i * CHAR_SIZE_BIT) - j];
        }

        stream << std::hex << c.to_ulong();

    }


    return stream.str();
}