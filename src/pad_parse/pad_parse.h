//
// Created by ahmad on 6/3/18.
//

#ifndef BITCOIN_ENCRYPTION_PADDING_PARSING_H
#define BITCOIN_ENCRYPTION_PADDING_PARSING_H

#include <bitset>
#include <string>
#include <vector>
#include "../const.h"

// Flags for Code
#define VECTORIZED_PAD_PARSE_IMPLEMENTATION         // Determine the output can be vector or not
#define PAD_PARSE_LOG_ENABLE                        // Enable logging for this function


#ifndef VECTORIZED_PAD_PARSE_IMPLEMENTATION
std::bitset<MAX_MESSAGE_SIZE> *pad_parse(std::string message, size_t &message_block_count);
#else // VECTORIZED_PAD_PARSE_IMPLEMENTATION
std::vector<std::bitset<MAX_MESSAGE_SIZE>> pad_parse(std::string message, size_t &message_block_count);
#endif // VECTORIZED_PAD_PARSE_IMPLEMENTATION

#endif //BITCOIN_ENCRYPTION_PADDING_PARSING_H
