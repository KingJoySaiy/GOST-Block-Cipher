#ifndef GOST_RIPEMD256_H
#define GOST_RIPEMD256_H

#include "const.h"

//using namespace RIPEMD;

class ripemd256 {
private:
    //expand string to multiple of 512, each block512 contains 512 bits
    static vector<RIPEMD::block512>  expand(string str) {    //expand word(highest bit first)

        while (str.length() % 64) {  //append 0 in the back
            str.push_back(0);
        }

        vector<RIPEMD::block512> res;       //64 characters as a block512
        RIPEMD::block512 tmp;
        int id = 0;
        for (int i = 0; i < str.length(); i++) {
            tmp.x[id] = (tmp.x[id] << 8) + str[i];
            if (i % 4 == 3) id++;
            if (id == 16) {
                res.push_back(tmp);
                memset(tmp.x, 0, sizeof(tmp.x));
                id = 0;
            }
        }
        return res;
    }

    static void compress(const vector<RIPEMD::block512> &blocks, uint32_t h[]) {

        for (RIPEMD::block512 p : blocks) {
            uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
            uint32_t aa = h[4], bb = h[5], cc = h[6], dd = h[7];

            //start iterate
            for (uint32_t j = 0; j < 64; j++) {
                uint32_t t = RIPEMD::rol_s(add(add(add(a, RIPEMD::f(j, b, c, d)), p.x[RIPEMD::r[j]]), RIPEMD::k(j)), j);
                a = d;
                d = c;
                c = b;
                b = t;
                t = RIPEMD::rol_ss(add(add(add(aa, RIPEMD::f(63 - j, bb, cc, dd)), p.x[RIPEMD::rr[j]]), RIPEMD::kk(j)), j);
                aa = dd;
                dd = cc;
                cc = bb;
                bb = t;
                if (j == 15) swap(a, aa);
                else if (j == 31) swap(b, bb);
                else if (j == 47) swap(c, cc);
                else if (j == 63) swap(d, dd);
            }
            h[0] += a;
            h[1] += b;
            h[2] += c;
            h[3] += d;
            h[4] += aa;
            h[5] += bb;
            h[6] += cc;
            h[7] += dd;
            //end iterate, update h0-h7
        }
    }

public:

    //get the string, return hash message
    static void run(const string &str, uint32_t message[8]) {

        for (int i = 0; i < 8; i++) {   //initialize message
            message[i] = RIPEMD::iniNumber[i];
        }
        compress(expand(str), message); //expand the string, then compress
    }
};


#endif //GOST_RIPEMD256_H
