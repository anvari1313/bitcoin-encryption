//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_COMPRESSION_H
#define BITCOIN_ENCRYPTION_COMPRESSION_H

#include <vector>
#include "../types.h"

const Prime first_primes[] = {
        0x6a09e667,         // H(0, 0)
        0xbb67ae85,         // H(0, 1)
        0x3c6ef372,         // H(0, 2)
        0xa54ff53a,         // H(0, 3)
        0x510e527f,         // H(0, 4)
        0x9b05688c,         // H(0, 5)
        0x1f83d9ab,         // H(0, 6)
        0x5be0cd19          // H(0, 7)
};

#ifndef XILINIX_SDK
HashBlock compress(std::vector<ExpansionBlockVec> m);
#else
void compress_(ExpansionBlock *m, int &m_size, HashBlock &block);
#endif


#endif //BITCOIN_ENCRYPTION_COMPRESSION_H
