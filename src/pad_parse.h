//
// Created by ahmad on 6/3/18.
//

#ifndef BITCOIN_ENCRYPTION_PADDING_PARSING_H
#define BITCOIN_ENCRYPTION_PADDING_PARSING_H

#include <bitset>
#include <string>
#include "const.h"


std::bitset<MAX_MESSAGE_SIZE> *pad_parse(std::string message, size_t &message_block_count);

#endif //BITCOIN_ENCRYPTION_PADDING_PARSING_H
