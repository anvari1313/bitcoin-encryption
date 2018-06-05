//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_TOOLS_H
#define BITCOIN_ENCRYPTION_TOOLS_H

#include "../types.h"

ExpansionInputBlock rot(unsigned int n, ExpansionInputBlock x);
ExpansionInputBlock shf(unsigned int n, ExpansionInputBlock x);

#endif //BITCOIN_ENCRYPTION_TOOLS_H
