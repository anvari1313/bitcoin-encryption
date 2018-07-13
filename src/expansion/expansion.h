//
// Created by ahmad on 6/5/18.
//

#ifndef BITCOIN_ENCRYPTION_EXPANSION_H
#define BITCOIN_ENCRYPTION_EXPANSION_H

#include <vector>
#include "../types.h"

std::vector<ExpansionBlockVec> expand(std::vector<PadParseMessageBlock> m);
void expand_(PadParseMessageBlock *m, int pad_parse_block_count, ExpansionBlock *ws, int &ws_count);

#endif //BITCOIN_ENCRYPTION_EXPANSION_H
