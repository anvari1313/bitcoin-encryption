//
// Created by ahmad on 6/5/18.
//

#include "tools.h"
#include "../expansion/tools.h"

ExpansionBlock big_sigma0(ExpansionBlock x)
{
    return rot(2, x) ^ rot(13, x) ^ rot(22, x) ^ shf(7, x);
}

ExpansionBlock big_sigma1(ExpansionBlock x)
{
    return rot(6, x) ^ rot(11, x) ^ rot(25, x);
}

ExpansionBlock big_sigma2(ExpansionBlock x)
{
    return rot(2, x) ^ rot(3, x) ^ rot(15, x) ^ shf(5, x);
}

ExpansionBlock ch(ExpansionBlock x, ExpansionBlock y, ExpansionBlock z)
{
    return (x & y) ^ (~y & z) ^ (~x & z);
}

ExpansionBlock maj(ExpansionBlock x, ExpansionBlock y, ExpansionBlock z)
{
    return (x & z) ^ (x & y) ^ (y & z);
}
