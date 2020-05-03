//
// Created by Joy on 2020/5/2.
//

#ifndef GOST_ENCRYPTDECRYPT_H
#define GOST_ENCRYPTDECRYPT_H

#include <bits/stdc++.h>
#include "Algorithm/gostDemo.h"
#include "Algorithm/ripemd256.h"
#include "Modes/ECB.h"
#include "Modes/CBC.h"
#include "Modes/CFB.h"
#include "Modes/OFB.h"
#include "Modes/CTR.h"

using namespace std;

class EncryptDecrypt {
public:
    static string run(const string& text, const string& key, int mode, bool isEncrypt) {  //return cipher text in hexadecimal format

        if (isEncrypt) {
            switch (mode) {
                case 0 :
                    return ECB::encrypt(text, key);
                case 1 :
                    return CBC::encrypt(text, key);
                case 2:
                    return CFB::encrypt(text, key);
                case 3 :
                    return OFB::encrypt(text, key);
                case 4:
                    return CTR::encrypt(text, key);
            }
        } else {
            switch (mode) {
                case 0 :
                    return ECB::decrypt(text, key);
                case 1 :
                    return CBC::decrypt(text, key);
                case 2:
                    return CFB::decrypt(text, key);
                case 3 :
                    return OFB::decrypt(text, key);
                case 4:
                    return CTR::decrypt(text, key);
            }
        }
    }

};

#endif //GOST_ENCRYPTDECRYPT_H
