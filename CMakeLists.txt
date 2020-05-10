cmake_minimum_required(VERSION 3.16)
project(GOST)

set(CMAKE_CXX_STANDARD 14)

add_executable(GOST main.cpp Algorithm/const.h Algorithm/gostDemo.h Algorithm/ripemd256.h Modes/ECB.h Modes/CBC.h Modes/CFB.h Modes/CTR.h Modes/OFB.h Interface/EncryptDecrypt.h Interface/transform.h)