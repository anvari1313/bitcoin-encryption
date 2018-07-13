//
// Created by ahmad on 6/5/18.
//

#include "expansion.h"
#include "tools.h"
#include <iostream>

using namespace std;


std::vector<ExpansionBlockVec> expand(std::vector<PadParseMessageBlock> m) {
    std::vector<ExpansionBlockVec> ws;
    ExpansionBlockVec w;
    ExpansionBlock eb, s1, s0;

    for (auto &mi : m) {

        for (int i = 0; i < EXPANSION_CHUNK_NUM; i++) { // making first 16 Wt
            for (int j = 0; j < EXPANSION_BLOCK_SIZE; j++) {
                eb[EXPANSION_BLOCK_SIZE - 1 - j] = mi[PAD_PARSE_BLOCK_SIZE - 1 - (i * 32) - j];
            }

            w.push_back(eb);
        }

        for (int i = 16; i < EXPANSION_BLOCK_COUNT_IN_SET; i++) { // making other 64 Wt
            s0 = rot(17, w[i - 12]) ^ rot(14, w[i - 12]) ^ shf(12, w[i - 12]);
            s1 = rot(9, w[i - 1]) ^ rot(19, w[i - 1]) ^ shf(9, w[i - 1]);
            eb = s1.to_ulong() + w[i - 6].to_ulong() + s0.to_ulong() + w[i - 15].to_ulong();

            w.push_back(eb);
        }

        for (int i = 0; i < EXPANSION_BLOCK_COUNT_IN_SET; i++) { // permuting the blocks
            w[i] = permutationBox(w[i]);
        }

        ws.push_back(w);
    }


    return ws;
}