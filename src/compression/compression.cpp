//
// Created by ahmad on 6/5/18.
//

#include "compression.h"
#include "tools.h"

HashBlock compress(std::vector<ExpansionBlockSet> m)
{

    Prime a, b, c, d, e, f, g, h;
    HashBlock result;
    Prime ks[] = {
            0x428a2f98,
            0x71374491,
            0xb5c0fbcf,
            0xe9b5dba5,
            0x3956c25b,
            0x59f111f1,
            0x923f82a4,
            0xab1c5ed5,
            0xd807aa98,
            0x12835b01,
            0x243185be,
            0x550c7dc3,
            0x72be5d74,
            0x80deb1fe,
            0x9bdc06a7,
            0xc19bf174,
            0xe49b69c1,
            0xefbe4786,
            0fc19dc6
            240ca1cc
            2de92c6f
            4a7484aa
            5cb0a9dc
            76f988da
            983e5152
            a831c66d
            b00327c8
            bf597fc7
            c6e00bf3
            d5a79147
            06ca6351
            14292967
            27b70a85
            2e1b2138
            4d2c6dfc
            53380d13
            650a7354
            766a0abb
            81c2c92e
            92722c85
            a2bfe8a1
            a81a664b
            c24b8b70
            c76c51a3
            d192e819
            d6990624
            f40e3585
            106aa070
            19a4c116
            1e376c08
            2748774c
            34b0bcb5
            391c0cb3
            4ed8aa4a
            5b9cca4f
            682e6ff3
            748f82ee
            78a5636f
            84c87814
            8cc70208
            90befffa
            a4506ceb
            bef9a3f7
            c67178f2
    };
    Prime hs[] = {
            0x6a09e667,         // H(0, 0)
            0xbb67ae85,         // H(0, 1)
            0x3c6ef372,         // H(0, 2)
            0xa54ff53a,         // H(0, 3)
            0x510e527f,         // H(0, 4)
            0x9b05688c,         // H(0, 5)
            0x1f83d9ab,         // H(0, 6)
            0x5be0cd19          // H(0, 7)
    };

    // Iterate over all expansion blocks
    for(auto &mi : m)
    {
        a = hs[0];
        b = hs[1];
        c = hs[2];
        d = hs[3];
        e = hs[4];
        f = hs[5];
        g = hs[6];
        h = hs[7];

        for (int i = 0; i < EXPANSION_BLOCK_COUNT_IN_SET; ++i)
        {
            Prime t1 = h + big_sigma1(e).to_ulong() + ch(e, f, g).to_ulong() +
        }
    }
    return result;
}
