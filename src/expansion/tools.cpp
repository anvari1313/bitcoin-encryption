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
    while(stream.good()) {
        std::bitset<8> bits;
        stream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}