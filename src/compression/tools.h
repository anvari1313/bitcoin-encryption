//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_COMPRESSION_TOOLS_H
#define BITCOIN_ENCRYPTION_COMPRESSION_TOOLS_H

#include "../types.h"

ExpansionBlock big_sigma0(ExpansionBlock x);
ExpansionBlock big_sigma1(ExpansionBlock x);
ExpansionBlock big_sigma2(ExpansionBlock x);

ExpansionBlock ch(ExpansionBlock x, ExpansionBlock y, ExpansionBlock z);
ExpansionBlock maj(ExpansionBlock x, ExpansionBlock y, ExpansionBlock z);

#endif //BITCOIN_ENCRYPTION_COMPRESSION_TOOLS_H
