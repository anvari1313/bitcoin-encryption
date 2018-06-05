//
// Created by ahmad on 6/4/18.
//

#include "bitstream.h"
#include <math.h>

void bitstream_init(BitStream &bitstream, size_t size)
{
    bitstream.bits = new bool[size];
    bitstream.size = size;
}

void bitstream_init(BitStream &bitstream, unsigned long long initial_value)
{

}

//bool &operator [](BitStream &bitstream, size_t index)
//{
//    return bitstream.bits[index];
//}
//
//std::ostream &operator <<(std::ostream &stream, BitStream &bitstream)
//{
//    for (int i = 0; i < bitstream.size; ++i) {
//        stream << bitstream.bits[i];
//    }
//
//    return stream;
//}