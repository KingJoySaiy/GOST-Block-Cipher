#ifndef GOST_ENCRYPTDECRYPT_H
#define GOST_ENCRYPTDECRYPT_H

#include "../Modes/ECB.h"
#include "../Modes/CBC.h"
#include "../Modes/CFB.h"
#include "../Modes/OFB.h"
#include "../Modes/CTR.h"
#include "transform.h"
#include "../Algorithm/ripemd256.h"
#include <fstream>

class EncryptDecrypt {
private:
    static string runEncrypt(const string &plainText, const string &key, const int &mode) {

        uint32_t message[8];
        ripemd256::run(key, message);   //get message by hashing key

        vector<uint64_t> texts = TRANSFORM::expandGost(plainText);    //get text by expanding plain text

        switch (mode) {
            case 0 :
                ECB::encrypt(texts, message);
                break;
            case 1 :
                CBC::encrypt(texts, message);
                break;
            case 2:
                CFB::encrypt(texts, message);
                break;
            case 3 :
                OFB::encrypt(texts, message);
                break;
            default:
                CTR::encrypt(texts, message);
                break;
        }

        string res;
        for (auto &text : texts) {  //append each cipher text to result
            res.append(TRANSFORM::bit64ToHex16(text));
        }
        return res;
    }

    static string runDecrypt(const string &cipherText, const string &key, const int &mode) {

        uint32_t message[8];
        ripemd256::run(key, message);   //get message by hashing key
        vector<uint64_t> texts = TRANSFORM::hex16Tobit64(cipherText);   //transform hex to array of 64-bit

        switch (mode) {
            case 0 :
                ECB::decrypt(texts, message);
                break;
            case 1 :
                CBC::decrypt(texts, message);
                break;
            case 2:
                CFB::decrypt(texts, message);
                break;
            case 3 :
                OFB::decrypt(texts, message);
                break;
            default:
                CTR::decrypt(texts, message);
                break;
        }

        return TRANSFORM::resetGost(texts);  //reset texts to characters
    }

public:
    //global interface
    static string run(const string &text, const string &key, const string &mode,
                      const bool &isDecrypt, const bool &isFile) {

        if (mode.compare("0") and mode.compare("1") and mode.compare("2")
            and mode.compare("3") and mode.compare("4")) {
            throw "mode error";
        }
        if (isFile) {
            string realText = TRANSFORM::readFile(text);
            return TRANSFORM::writeFile(text, run(realText, key, mode, isDecrypt, false));
        } else if (isDecrypt) {
            return runDecrypt(text, key, atoi(mode.c_str()));  //check is encryption or not
        } else {
            return runEncrypt(text, key, atoi(mode.c_str()));
        }
    }
};

#endif //GOST_ENCRYPTDECRYPT_H
