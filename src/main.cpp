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