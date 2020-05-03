#ifndef GOST_GOSTDEMO_H
#define GOST_GOSTDEMO_H

#include "const.h"

class gostDemo {
private:
    //round_function, return <left, right>
    static void round(pair<uint32_t, uint32_t> &data, const uint32_t &key,
               const uint4_t sBox[][16]) {

        uint32_t tmp = (0ll + data.first + key) % ((1ULL << 32));
        uint4_t block[8];   //8 4-bit blocks
        for (int i = 7; i >= 0; i--) {
            block[i] = tmp % 16;    //get each block
            block[i] = sBox[i][block[i]];   //get result from s-box
            tmp >>= 4;
        }

        tmp = 0;
        for (uint4_t &p : block) {   //get new temporary
            tmp = tmp * 16 + p;
        }
        tmp = rol(tmp, 11);   //cyclically rotate tmp left by 11 bits
        data.second ^= tmp;
        swap(data.first, data.second);  //swap left & right
    }

public:

    //encrypt plain text
    static void runEncrypt(uint64_t &data, const uint32_t key[8]) {

        //set first 32 bit as left, others as right
        pair<uint32_t, uint32_t> tmp = make_pair(data >> 32, data % (1ULL << 32));
        for (int i = 0; i < 32; i++) {
            round(tmp, key[i % 8], GOST::sBoxConst);
            if (i == 31) {  //swap twice to maintain initial order
                swap(tmp.first, tmp.second);
            }
        }
        data = (1ULL << 32) * tmp.first + tmp.second;   //update data
    }

    //decrypt cipher text (almost same as the encryption)
    static void runDecrypt(uint64_t &data, const uint32_t key[8]) {

        pair<uint32_t, uint32_t> tmp = make_pair(data >> 32, data % (1ULL << 32));
        for (int i = 31; i >= 0; i--) {
            round(tmp, key[i % 8], GOST::sBoxConst);    //just changed the order of using keys
            if (i == 0) {
                swap(tmp.first, tmp.second);
            }
        }
        data = (1ULL << 32) * tmp.first + tmp.second;
    }
};


#endif //GOST_GOSTDEMO_H
