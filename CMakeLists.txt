cmake_minimum_required(VERSION 3.10)
project(bitcoin_encryption)

set(CMAKE_CXX_STANDARD 17)

add_executable(bitcoin_encryption src/main.cpp src/pad_parse/pad_parse.cpp src/pad_parse/pad_parse.h src/const.h src/bitstream/bitstream.cpp src/bitstream/bitstream.h src/types.h src/expansion/tools.cpp src/expansion/tools.h src/compression/compression.cpp src/compression/compression.h src/compression/tools.cpp src/compression/tools.h)