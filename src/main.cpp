#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "pad_parse/pad_parse.h"
#include "bitstream/bitstream.h"
#include "compression/compression.h"
#include "expansion/tools.h"
#include "expansion/expansion.h"

using namespace std;

#ifndef XILINIX_SDK
HashBlock sha256(string message);
#endif

int main() {
    bitset<8> a, b, c;
    a = 'a'; b = 'b'; c = 2 ;
    cout << a << b << " " <<c << endl;
    PadParseMessageBlock mblock[4];
    int pad_parse_block_count;
    pad_parse_("abc", 3, mblock, pad_parse_block_count);
    for (int i = 0; i < pad_parse_block_count; ++i) {
        cout << mblock[i];
    }
    ExpansionBlock expansion_block[pad_parse_block_count * 64];
    int expansion_block_count;
    expand_(mblock, pad_parse_block_count, expansion_block,expansion_block_count);
    for (int j = 0; j < expansion_block_count; ++j) {
        cout << expansion_block[j].to_ulong() << endl;
    }

    HashBlock h;
    compress_(expansion_block, expansion_block_count, h);
    cout << h << endl;


#ifndef XILINIX_SDK

    string message;
    cin >> message;

    HashBlock firstResult = sha256(message);
    cout << firstResult << endl;
//    cout << endl << hashBlockToHex(firstResult) << endl;
#endif
    return 0;

}

#ifndef XILINIX_SDK
HashBlock sha256(string message) {
    auto blocks = pad_parse(message.c_str(), message.size());

    auto ws = expand(blocks);
    for (auto w:ws)
    {
        for (auto wi: w)
        {
            cout << wi.to_ulong() << endl;
        }
    }


    return compress(ws);
}
#endif