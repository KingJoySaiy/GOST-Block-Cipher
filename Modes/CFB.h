#ifndef GOST_CFB_H
#define GOST_CFB_H

#include <vector>
#include "../Algorithm/gostDemo.h"

using std::vector;

class CFB {
private:
    const static uint64_t initialVector = 0xDDB233ULL;  //set an initial vector (secret)
public:
    static void encrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //encrypt by CBC block cipher mode

        uint64_t tmp = initialVector;
        for (auto &text : texts) {
            gostDemo::runEncrypt(tmp, message);
            text ^= tmp;    //xor with tmp
            tmp = text;
        }
    }

    static void decrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //decrypt by CBC block cipher mode

        uint64_t tmp, preText = initialVector;
        for (auto &text : texts) {
            tmp = text;     //record the pre-text
            gostDemo::runEncrypt(preText, message); //also use 'runEncrypt'
            text ^= preText;    //xor with pre-text (first with initial vector)
            preText = tmp;
        }
    }
};

#endif //GOST_CFB_H
