//
// Created by ahmad on 6/3/18.
//

#include "pad_parse.h"
#include <algorithm>    // std::for_each
#include <iostream>

using namespace std;

#ifndef VECTORIZED_PAD_PARSE_IMPLEMENTATION
std::bitset<MAX_MESSAGE_SIZE> *pad_parse(std::string message, size_t &message_block_count)
{
    std::bitset<MAX_MESSAGE_SIZE> main_message_size(message.length());
#ifdef PAD_PARSE_LOG_ENABLE
    cout << "Main message size :" << main_message_size << endl;
#endif // PAD_PARSE_LOG_ENABLE

    // Counting how many blocks are needed with message(Counting ceiling of the block count)
    message_block_count = (message.length() % MAX_PAYLOAD_BLOCK_SIZE_BYTE) ?
                          message.length() / MAX_PAYLOAD_BLOCK_SIZE_BYTE + 1 : message.length() /
                                                                               MAX_PAYLOAD_BLOCK_SIZE_BYTE;
#ifdef PAD_PARSE_LOG_ENABLE
    cout << "Message block count :" << message_block_count << endl;
#endif // PAD_PARSE_LOG_ENABLE

    // Initializing the array of blocks
    auto blocks = new std::bitset<MAX_MESSAGE_SIZE>[message_block_count];
    int message_blocks_list_index = 0;      // Index iterating on blocks array

    int byte_proceed = 0;                   // Indicate how many bytes proceeded in message
    std::bitset<MAX_MESSAGE_SIZE> message_block;

    int message_bit_proceed = 0;

    for (int i = 0; i < message.length(); ++i) {
        if (i % MAX_PAYLOAD_BLOCK_SIZE_BYTE == 0 && i != 0) {
            message_block[MAX_MESSAGE_SIZE - message_bit_proceed - 1] = true;
            message_block |= main_message_size;
            blocks[message_blocks_list_index++] = message_block;
            message_bit_proceed = 0;
            byte_proceed = 0;
#ifdef PAD_PARSE_LOG_ENABLE
            cout << "Code here 1 run" << endl;
#endif // PAD_PARSE_LOG_ENABLE
        }
#ifdef PAD_PARSE_LOG_ENABLE
        cout << "Byte : " << message[i] << " ";
#endif // PAD_PARSE_LOG_ENABLE
        std::bitset<CHAR_SIZE_BIT> char_bits((unsigned long long int) message[i]);
#ifdef PAD_PARSE_LOG_ENABLE
        cout << char_bits << endl;
#endif // PAD_PARSE_LOG_ENABLE

        for (int j = 0; j < CHAR_SIZE_BIT; ++j) {

            message_block[MAX_MESSAGE_SIZE - message_bit_proceed - j - 1] = char_bits[CHAR_SIZE_BIT - j - 1];
        }
#ifdef PAD_PARSE_LOG_ENABLE
        cout << "Message Block " << message_block << endl;
        cout << "Message bit proceed " << message_bit_proceed << endl;
#endif // PAD_PARSE_LOG_ENABLE
        message_bit_proceed += CHAR_SIZE_BIT;
        byte_proceed++;
    }

    if (message_bit_proceed != MAX_PAYLOAD_BLOCK_SIZE_BYTE)
    {
        message_block[message_bit_proceed] = true;
        message_block |= main_message_size;
#ifdef PAD_PARSE_LOG_ENABLE
        cout << "Message Block " << message_block << endl;
        cout << "Code here 2 run" << endl;
#endif // PAD_PARSE_LOG_ENABLE
        blocks[message_blocks_list_index] = message_block;
    }

    return blocks;
}
#else
std::vector<std::bitset<MAX_MESSAGE_SIZE>> pad_parse(std::string message, size_t &message_block_count)
{
    std::bitset<MAX_MESSAGE_SIZE> main_message_size(message.length());
#ifdef PAD_PARSE_LOG_ENABLE
    cout << "Main message size :" << main_message_size << endl;
#endif // PAD_PARSE_LOG_ENABLE

    // Initializing the array of blocks
    std::vector<std::bitset<MAX_MESSAGE_SIZE>> blocks;

    int byte_proceed = 0;                   // Indicate how many bytes proceeded in message
    std::bitset<MAX_MESSAGE_SIZE> message_block;

    int message_bit_proceed = 0;

    for (int i = 0; i < message.length(); ++i) {
        if (i % MAX_PAYLOAD_BLOCK_SIZE_BYTE == 0 && i != 0) {
            message_block[MAX_MESSAGE_SIZE - message_bit_proceed - 1] = 1;
            message_block |= main_message_size;
            blocks.push_back(message_block);
            message_bit_proceed = 0;
            byte_proceed = 0;
#ifdef PAD_PARSE_LOG_ENABLE
            cout << "Code here 1 run" << endl;
#endif // PAD_PARSE_LOG_ENABLE
        }
#ifdef PAD_PARSE_LOG_ENABLE
        cout << "Byte : " << message[i] << " ";
#endif // PAD_PARSE_LOG_ENABLE
        std::bitset<CHAR_SIZE_BIT> char_bits((unsigned long long int) message[i]);
#ifdef PAD_PARSE_LOG_ENABLE
        cout << char_bits << endl;
#endif // PAD_PARSE_LOG_ENABLE
        for (int j = 0; j < CHAR_SIZE_BIT; ++j) {

            message_block[MAX_MESSAGE_SIZE - message_bit_proceed - j - 1] = char_bits[CHAR_SIZE_BIT - j - 1];
        }
#ifdef PAD_PARSE_LOG_ENABLE
        cout << "Message Block " << message_block << endl;
        cout << "Message bit proceed " << message_bit_proceed << endl;
#endif // PAD_PARSE_LOG_ENABLE
        message_bit_proceed += CHAR_SIZE_BIT;
        byte_proceed++;
    }

    if (message_bit_proceed != MAX_PAYLOAD_BLOCK_SIZE_BYTE)
    {
        message_block[MAX_MESSAGE_SIZE - message_bit_proceed - 1] = 1;
        message_block |= main_message_size;
#ifdef PAD_PARSE_LOG_ENABLE
        cout << "Message Block " << message_block << endl;
        cout << "Code here 2 run" << endl;
#endif // PAD_PARSE_LOG_ENABLE
        blocks.push_back(message_block);
    }

    return blocks;
}
#endif