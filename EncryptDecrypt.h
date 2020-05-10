#ifndef GOST_ENCRYPTDECRYPT_H
#define GOST_ENCRYPTDECRYPT_H

#include "Modes/ECB.h"
#include "Modes/CBC.h"
#include "Modes/CFB.h"
#include "Modes/OFB.h"
#include "Modes/CTR.h"
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

    template <typename T>
    static void run(const string &FilePath, const string &key, const int &mode, const bool &isEncrypt, T anything) {

        try {
            if (mode < 0 or mode >= 5) throw "Mode not in[0, 5)!";
            std::fstream file;
            file.open(FilePath, std::ios::in);
            if (file.fail()) {
                throw "File not found!";
            }

            string text;
            char c;
            while (!file.eof()) {
                if((c = file.get()) == EOF) continue;   //dismiss EOF
                text.push_back(c);
            }
            file.close();

            text = run(text, key, mode, isEncrypt);

            file.open(FilePath, std::ios::out);
            for (auto &c : text) {
                file.put(c);
            }
            file.close();

        } catch (const string &error) {
            cout << error << endl;
        }
    }

};

#endif //GOST_ENCRYPTDECRYPT_H
