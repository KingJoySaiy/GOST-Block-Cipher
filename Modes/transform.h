//
// Created by Joy on 2020/5/2.
//

#ifndef GOST_TRANSFORM_H
#define GOST_TRANSFORM_H

#include <bits/stdc++.h>
#include "../Algorithm/gostDemo.h"
#include "../Algorithm/ripemd256.h"

using namespace std;

class TRANSFROM {
private:
    static string bit64ToHex16(uint64_t num) { //transform 64-bit to 16-hex

        string res;
        while (num) {
            if (isdigit(num % 16 + '0')) {
                res.push_back(num % 16 + '0');
            } else {
                res.push_back(num % 16 - 10 + 'a');
            }
            num >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    static vector<uint64_t> hex16Tobit64(string hex) {


    }

    static vector<uint64_t> expandGost(string str) {    //expand string to 64-bit

        while(str.length() % 8) {  //append 0 in the back
            str.append(0);
        }

        vector<uint64_t> res;   //8 characters as a block64
        uint64_t tmp = 0;
        for (int i = 0; i < str.length(); i++) {
            tmp = (tmp << 8) + str[i];
            if (i % 8 == 7) {
                res.push_back(tmp);
                tmp = 0;
            }
        }
        return res;
    }

    static string resetGost(vector<uint64_t> texts) {   //undo the expand

        for (auto &text : texts) {

        }
    }

public:
    static void preEncrypt(const string &plainText, const string &key, uint32_t message[8], vector<uint64_t> &texts) {

        ripemd256::run(key, message);   //get message by hashing key
        texts = expandGost(plainText);    //get text by expanding plain text
    }

    static string postEncrypt(const vector<uint64_t> &texts) {

        string res;
        for (auto &text : texts) {  //append each cipher text to result
            res.append(TRANSFROM::bit64ToHex16(text));
        }
        return res;
    }

    static void preDecrypt(const string &cipherText, const string &key, uint32_t message[8], vector<uint64_t> &texts) {

        ripemd256::run(key, message);   //get message by hashing key
        texts = TRANSFROM::hex16Tobit64(cipherText);   //transform hex to array of 64-bit
    }

    static string postDecrypt(const vector<uint64_t> &texts) {

        return resetGost(texts);  //reset texts to characters
    }

}

#endif //GOST_TRANSFORM_H
