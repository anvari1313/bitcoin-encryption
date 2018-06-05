//
// Created by ahmad on 6/4/18.
//

#ifndef BITCOIN_ENCRYPTION_BITSTREAM_H
#define BITCOIN_ENCRYPTION_BITSTREAM_H

#include <cstdlib>
#include <ostream>

struct BitStream{
    bool *bits;
    size_t size;
};

void bitstream_init(BitStream &bitstream, size_t size);
void bitstream_init(BitStream &bitstream, unsigned long long initial_value);


bool &operator [](BitStream &bitstream, bool &value);
std::ostream &operator <<(std::ostream &stream, BitStream &bitstream);

#endif //BITCOIN_ENCRYPTION_BITSTREAM_H
