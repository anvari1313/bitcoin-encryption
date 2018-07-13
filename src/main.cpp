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

HashBlock sha256(string message);

int main() {
    bitset<4> a = 18;
    bitset<4> b = 12;
    bitset<4> c = 6;
    bitset<4> d = 11;
    string result = a.to_string() + b.to_string() + c.to_string() + d.to_string();
    bitset<16> res(result);
    cout << "String : " << result << endl;
    cout << "Bitset : " << res << endl;
    cout << "ULong  : " << res.to_ulong() << endl;
    string message;
    cin >> message;

    HashBlock firstResult = sha256(message);

    cout << endl << hashBlockToHex(firstResult) << endl;


    return 0;

}

HashBlock sha256(string message) {
    auto blocks = pad_parse(message);

    auto ws = expand(blocks);


    return compress(ws);
}