#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "pad_parse/pad_parse.h"
#include "bitstream/bitstream.h"
#include "compression/compression.h"

using namespace std;

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
    auto blocks = pad_parse(message);
    cout << "-------------------------------------------------------------------------------" << endl;
    for(auto &block : blocks)
    {
        cout << block << endl;
    }

    return 0;
}