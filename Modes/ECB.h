#ifndef GOST_ECB_H
#define GOST_ECB_H

#include <vector>

using std::vector;

class ECB {
public:
    static void encrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //encrypt by ECB block cipher mode
        for (auto &text : texts) {  //encrypt each plain text in order
            gostDemo::runEncrypt(text, message);
        }
    }

    static void decrypt(vector<uint64_t> &texts, uint32_t message[8]) {   //decrypt by ECB block cipher mode

        for (auto &text : texts) {  //decrypt each cipher text in order
            gostDemo::runDecrypt(text, message);
        }
    }
};

#endif //GOST_ECB_H
