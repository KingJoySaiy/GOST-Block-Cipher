#ifndef GOST_ENCRYPTDECRYPT_H
#define GOST_ENCRYPTDECRYPT_H

#include "../Modes/ECB.h"
#include "../Modes/CBC.h"
#include "../Modes/CFB.h"
#include "../Modes/OFB.h"
#include "../Modes/CTR.h"
#include "transform.h"
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
    static string run(const string &text, const string &key, const int &mode, const bool &isEncrypt) {

        try {
            if (mode < 0 or mode >= 5) {
                throw "Mode Error";
            }
            if (isEncrypt) {
                return runEncrypt(text, key, mode);  //check is encryption or not
            }
            return runDecrypt(text, key, mode);
        } catch (const string &error) {
            cout << error << endl;
        }
    }

    //consider as File-path if contains 5 parameters
    template <typename T>
    static void run(const string &filePath, const string &key, const int &mode, const bool &isEncrypt, T anything) {

        try {
            string text = TRANSFORM::readFile(filePath);
            TRANSFORM::writeFile(filePath, run(text, key, mode, isEncrypt));
        } catch (const string &error) {
            cout << error << endl;
        }
    }

};

#endif //GOST_ENCRYPTDECRYPT_H
