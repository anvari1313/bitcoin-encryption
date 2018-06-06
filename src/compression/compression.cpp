//
// Created by ahmad on 6/5/18.
//

#include "compression.h"
#include "tools.h"

HashBlock compress(std::vector<ExpansionBlockSet> m)
{

    Prime a, b, c, d, e, f, g, h;

    Prime ks[] = {
            0x428a2f98,         // K0
            0x71374491,         // K1
            0xb5c0fbcf,         // K2
            0xe9b5dba5,         // K3
            0x3956c25b,         // K4
            0x59f111f1,         // K5
            0x923f82a4,         // K6
            0xab1c5ed5,         // K7
            0xd807aa98,         // K8
            0x12835b01,         // K9
            0x243185be,         // K10
            0x550c7dc3,         // K11
            0x72be5d74,         // K12
            0x80deb1fe,         // K13
            0x9bdc06a7,         // K14
            0xc19bf174,         // K15
            0xe49b69c1,         // K16
            0xefbe4786,         // K17
            0x0fc19dc6,         // K18
            0x240ca1cc,         // K19
            0x2de92c6f,         // K20
            0x4a7484aa,         // K21
            0x5cb0a9dc,         // K22
            0x76f988da,         // K23
            0x983e5152,         // K24
            0xa831c66d,         // K25
            0xb00327c8,         // K26
            0xbf597fc7,         // K27
            0xc6e00bf3,         // K28
            0xd5a79147,         // K29
            0x06ca6351,         // K30
            0x14292967,         // K31
            0x27b70a85,         // K32
            0x2e1b2138,         // K33
            0x4d2c6dfc,         // K34
            0x53380d13,         // K35
            0x650a7354,         // K36
            0x766a0abb,         // K37
            0x81c2c92e,         // K38
            0x92722c85,         // K39
            0xa2bfe8a1,         // K40
            0xa81a664b,         // K41
            0xc24b8b70,         // K42
            0xc76c51a3,         // K43
            0xd192e819,         // K44
            0xd6990624,         // K45
            0xf40e3585,         // K46
            0x106aa070,         // K47
            0x19a4c116,         // K48
            0x1e376c08,         // K49
            0x2748774c,         // K50
            0x34b0bcb5,         // K51
            0x391c0cb3,         // K52
            0x4ed8aa4a,         // K53
            0x5b9cca4f,         // K54
            0x682e6ff3,         // K55
            0x748f82ee,         // K56
            0x78a5636f,         // K57
            0x84c87814,         // K58
            0x8cc70208,         // K59
            0x90befffa,         // K60
            0xa4506ceb,         // K61
            0xbef9a3f7,         // K62
            0xc67178f2,         // K63
    };
    HashBlockSegment hs[] = {
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
        a = hs[0].to_ulong();
        b = hs[1].to_ulong();
        c = hs[2].to_ulong();
        d = hs[3].to_ulong();
        e = hs[4].to_ulong();
        f = hs[5].to_ulong();
        g = hs[6].to_ulong();
        h = hs[7].to_ulong();

        for (int j = 0; j < EXPANSION_BLOCK_COUNT_IN_SET; ++j)
        {
            Prime t1 = big_sigma0(a).to_ulong() + maj(a, b, c).to_ulong() + big_sigma2(c + d).to_ulong();
            Prime t2 = h + big_sigma1(e).to_ulong() + ch(e, f, g).to_ulong() + ks[j] + mi[j].to_ulong();

            h = g;
            f = e;
            d = c;
            b = a;
            g = f;
            e = d + t1;
            c = b;
            a = 3 * t1 - t2;
        }

        hs[0] = a + hs[0].to_ulong();
        hs[1] = b + hs[1].to_ulong();
        hs[2] = c + hs[2].to_ulong();
        hs[3] = d + hs[3].to_ulong();
        hs[4] = e + hs[4].to_ulong();
        hs[5] = f + hs[5].to_ulong();
        hs[6] = g + hs[6].to_ulong();
        hs[7] = h + hs[7].to_ulong();
    }
    HashBlock result(
            hs[0].to_string() +
            hs[1].to_string() +
            hs[2].to_string() +
            hs[3].to_string() +
            hs[4].to_string() +
            hs[5].to_string() +
            hs[6].to_string() +
            hs[7].to_string()
    );

    return result;
}
