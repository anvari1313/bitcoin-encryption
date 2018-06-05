//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_TOOLS_H
#define BITCOIN_ENCRYPTION_TOOLS_H

#include "../types.h"

ExpansionBlock rot(unsigned int n, ExpansionBlock x);
ExpansionBlock shf(unsigned int n, ExpansionBlock x);

#endif //BITCOIN_ENCRYPTION_TOOLS_H
