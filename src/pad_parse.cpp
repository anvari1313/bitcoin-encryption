//
// Created by ahmad on 6/3/18.
//

#include "pad_parse.h"
#include <algorithm>    // std::for_each

std::bitset<MAX_MESSAGE_SIZE> *pad_parse(std::string message, size_t &message_block_count)
{
    std::bitset <MAX_MESSAGE_SIZE> parsed_message;


    // Counting how many blocks are needed with message(Counting ceiling of the block count)
    message_block_count = (message.length() % MAX_PAYLOAD_BLOCK_SIZE_BYTE) ?
            message.length() / MAX_PAYLOAD_BLOCK_SIZE_BYTE + 1 :
                                 message.length() / MAX_PAYLOAD_BLOCK_SIZE_BYTE;

    // Initializing the array of blocks
    auto *blocks = new std::bitset<MAX_MESSAGE_SIZE>[message_block_count];

    int byte_proceed = 0;       // Indicate how many bytes proceeded in message
    auto message_block;
    int message_blocks_list_index = 0;
    int message_bit_proceed;

    for (int i = 0; i < message.length(); ++i)
    {
        if (i % MAX_PAYLOAD_BLOCK_SIZE_BYTE == 0)
        {
            message_block = new std::bitset<MAX_MESSAGE_SIZE>;
            blocks[message_blocks_list_index] = message_block;
            message_bit_proceed = 0;
        }

        for (int j = 0; j < CHAR_SIZE_BIT; ++j) {
            std::bitset<CHAR_SIZE_BIT> char_bits(message[i]);

            for (int k = 0; k < CHAR_SIZE_BIT; ++k) {
                (*message_block)[message_bit_proceed] = char_bits[k];
            }

            message_bit_proceed += CHAR_SIZE_BIT;
        }
    }


    return blocks;
}