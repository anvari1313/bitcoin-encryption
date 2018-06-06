//
// Created by ahmad on 6/5/18.
//

#include "tools.h"

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
