#ifndef GOST_TRANSFORM_H
#define GOST_TRANSFORM_H

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

namespace TRANSFORM {
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

        if (hex.length() % 16 or hex.empty()) {
            throw "incorrect cipher-text";
        }
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

        int zero = 0;
        while (str.length() % 8) {  //append 0 in the back
            str.push_back(0);
            zero++;
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
        res.push_back(zero);
        return res;
    }

    static string resetGost(vector<uint64_t> texts) {   //undo the expand

        int ct = *texts.rbegin();
        texts.pop_back();

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

        if (ct > res.size()) {
            throw "incorrect cipher-text";
        } else {
            while (ct--) {  //erase NULL at the end
                if (res[res.size() - 1] != 0) throw "incorrect cipher-text";
                res.erase(res.end() - 1);
            }
        }
        return res;
    }

    static string readFile(const string &filePath) {

        std::fstream file;
        file.open(filePath, std::ios::in);
        if (file.fail()) {
            throw "fail to read file";
        }
        string text;
        char c;
        while (!file.eof()) {   //read file
            if ((c = file.get()) == EOF) continue;   //dismiss EOF
            text.push_back(c);
        }
        file.close();
        return text;
    }

    static string writeFile(const string &filePath, const string &text) {

        std::fstream file;
        file.open(filePath, std::ios::out);
        for (auto &c : text) {  //write back to the file
            file.put(c);
        }
        file.close();
        return "succeed to write the file";
    }
};

#endif //GOST_TRANSFORM_H
