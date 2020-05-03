//
// Created by Joy on 2020/5/2.
//

#ifndef GOST_ECB_H
#define GOST_ECB_H

#include "transform.h"

class ECB {
public:
    static string encrypt(const string &plainText, const string &key) {   //encrypt by ECB block cipher mode

        uint32_t message[8];
        vector<uint64_t> texts;
        TRANSFROM::preEncrypt(plainText, key, message, texts);

        for (auto &text : texts) {  //encrypt plain text
            gostDemo::run(text, message);
        }

        return TRANSFROM::postEncrypt(texts);
    }

    static string decrypt(const string &cipherText, const string &key) {   //decrypt by ECB block cipher mode

        uint32_t message[8];
        vector<uint64_t> texts;
        TRANSFROM::preDecrypt(cipherText, key, message, texts);

        for (auto &text : texts) {  //decrypt cipher text
            gostDemo::run(text, message);
        }

        return TRANSFROM::postDecrypt(texts);
    }
};

#endif //GOST_ECB_H
