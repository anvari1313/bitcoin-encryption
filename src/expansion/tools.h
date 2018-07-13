//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_EXPANSION_TOOLS_H
#define BITCOIN_ENCRYPTION_EXPANSION_TOOLS_H

#include "../types.h"

ExpansionBlock rot(unsigned int n, ExpansionBlock x);
ExpansionBlock shf(unsigned int n, ExpansionBlock x);
ExpansionBlock permutationBox(ExpansionBlock block);
std::string HashBlockToString(HashBlock block);
std::string hashBlockToHex(HashBlock block);
std::string expansionBlockToHex(ExpansionBlock block);
#endif //BITCOIN_ENCRYPTION_EXPANSION_TOOLS_H
