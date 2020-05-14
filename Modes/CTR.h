#ifndef GOST_CTR_H
#define GOST_CTR_H

#include <vector>
#include "../Algorithm/gostDemo.h"

using std::vector;

class CTR {
    const static uint64_t mod = uint64_t(1e9 + 7);  //set a module
public:
    static void encrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //encrypt by ECB block cipher mode

        uint64_t ct = 0, tmp;   //set a counter
        for (auto &text : texts) {
            tmp = ct;
            gostDemo::runEncrypt(tmp, message); //encrypt the counter
            text ^= tmp;    //update plain text
            ct = (ct + 1) % mod;    //update counter
        }
    }

    static void decrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //decrypt by ECB block cipher mode

        return encrypt(texts, message); //same as encryption
    }
};

#endif //GOST_CTR_H
