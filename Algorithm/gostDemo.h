#ifndef GOST_GOSTDEMO_H
#define GOST_GOSTDEMO_H

#include "const.h"

class gostDemo {
private:
    //round_function, return <left, right>
    static void round(uint32_t &left, uint32_t &right, const uint32_t &key, const uint4_t sBox[][16]) {

        uint32_t tmp = (0ll + left + key) % ((1ULL << 32));
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
        right ^= rol(tmp, 11);   //rotate tmp left by 11 bits, then update right
        swap(left, right);  //swap left & right
    }

public:

    //encrypt plain text
    static void runEncrypt(uint64_t &data, const uint32_t key[8]) {

        //set first 32 bit as left, others as right
        uint32_t left = (data >> 32), right = data % (1ULL << 32);
        for (int i = 0; i < 32; i++) {
            round(left, right, key[i % 8], GOST::sBoxConst);
            if (i == 31) {  //swap twice to maintain initial order
                swap(left, right);
            }
        }
        data = (1ULL << 32) * left + right;   //update data
    }

    //decrypt cipher text (almost same as the encryption)
    static void runDecrypt(uint64_t &data, const uint32_t key[8]) {

        uint32_t left = (data >> 32), right = data % (1ULL << 32);
        for (int i = 31; i >= 0; i--) {
            round(left, right, key[i % 8], GOST::sBoxConst);    //just changed the order of using keys
            if (i == 0) {
                swap(left, right);
            }
        }
        data = (1ULL << 32) * left + right;
    }
};


#endif //GOST_GOSTDEMO_H
