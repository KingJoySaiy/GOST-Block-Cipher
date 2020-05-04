#ifndef GOST_OFB_H
#define GOST_OFB_H

#include "transform.h"

class OFB {
private:
    const static uint64_t initialVector = 0xACBB1910ULL;  //set an initial vector (secret)
public:
    static void encrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //encrypt by CBC block cipher mode

        uint64_t tmp = initialVector;
        for (auto &text : texts) {
            gostDemo::runEncrypt(tmp, message);
            text ^= tmp;    //xor with tmp
        }
    }

    static void decrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //decrypt by CBC block cipher mode

        return encrypt(texts, message); //same as encryption
    }
};

#endif //GOST_OFB_H
