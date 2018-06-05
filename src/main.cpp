#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "pad_parse/pad_parse.h"
#include "bitstream/bitstream.h"
#include "compression/compression.h"

using namespace std;

int main() {
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