#ifndef GOST_TRANSFORM_H
#define GOST_TRANSFORM_H

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class TRANSFORM {
public:
    static string bit64ToHex16(uint64_t num) { //transform 64-bit to 16-hex

        string res;
        for (int ct = 16; ct; ct--) {
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

    static vector<uint64_t> hex16Tobit64(string hex) {  //transform hex to 64-bit array

        vector<uint64_t> res;
        uint64_t tmp = 0;
        for (int i = 0; i < hex.length(); i++) {
            if (isdigit(hex[i])) {
                tmp = (tmp << 4) + hex[i] - '0';
            } else {
                tmp = (tmp << 4) + hex[i] - 'a' + 10;
            }
            if (i % 16 == 15) {
                res.push_back(tmp);
                tmp = 0;
            }
        }
        return res;
    }

    static vector<uint64_t> expandGost(string str) {    //expand string to 64-bit

        while(str.length() % 8) {  //append 0 in the back
            str.push_back(0);
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

        string res, tmp;
        for (auto &text : texts) {  //append text to res
            tmp.clear();
            for (int i = 0; i < 8; i++) {
                tmp.push_back(text % (1ULL << 8));
                text >>= 8;
            }
            reverse(tmp.begin(), tmp.end());
            res.append(tmp);
        }

        for (int i = res.length() - 1; i >= 0; i--) {   //erase NULL at the end
            if (res[i] == 0) {
                res.erase(res.end() - 1);
            } else break;
        }
        return res;
    }
};

#endif //GOST_TRANSFORM_H
