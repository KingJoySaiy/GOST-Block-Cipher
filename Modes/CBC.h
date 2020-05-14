#ifndef GOST_CBC_H
#define GOST_CBC_H

#include <vector>
#include "../Algorithm/gostDemo.h"

using std::vector;

class CBC {
private:
    const static uint64_t initialVector = 0xABC9852ULL;  //set an initial vector (secret)
public:
    static void encrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //encrypt by CBC block cipher mode

        uint64_t tmp = initialVector;
        for (auto &text : texts) {
            text ^= tmp;    //xor with pre-text (first with initial vector)
            gostDemo::runEncrypt(text, message);
            tmp = text;
        }
    }

    static void decrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //decrypt by CBC block cipher mode

        uint64_t tmp, preText = initialVector;
        for (auto &text : texts) {
            tmp = text;     //record the pre-text
            gostDemo::runDecrypt(text, message);
            text ^= preText;    //xor with pre-text (first with initial vector)
            preText = tmp;
        }
    }
};

#endif //GOST_CBC_H
