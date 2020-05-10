#ifndef GOST_RIPEMD256_H
#define GOST_RIPEMD256_H

#include "const.h"

class ripemd256 {
private:
    //expand string to multiple of 512, each block512 contains 512 bits
    static vector<RIPEMD::block512>  expand(string str) {    //expand word

        ////start padding
        std::queue<bool> bit;
        for (auto &c : str) {   //1 character as 8 bits
            bit.push(c & 0x80);
            bit.push(c & 0x40);
            bit.push(c & 0x20);
            bit.push(c & 0x10);
            bit.push(c & 0x08);
            bit.push(c & 0x04);
            bit.push(c & 0x02);
            bit.push(c & 0x01);
        }
        std::bitset<64> len(bit.size());
        bit.push(1);    //pad 1
        while (bit.size() % 512 != 448) {   //pad 0 until 'size % 512 == 448'
            bit.push(0);
        }
        for (int i = 0; i < 64; i++) {  //pad initial length (64 bits)
            bit.push(len[i]);
        }
        ////end padding

        vector<RIPEMD::block512> res;   //result (512 bits as a block)
        for (int i = 0; i < bit.size(); i += 512) {
            RIPEMD::block512 tmp;
            for (uint32_t id = 0, now = 0; id < 16; id++, now = 0) {
                for (int ct = 32; ct--; ) {
                    now = now * 2 + bit.front();
                    bit.pop();
                }
                tmp.x[id] = now;
            }
            res.push_back(tmp);
        }
        return res;
    }

    static void compress(const vector<RIPEMD::block512> &blocks, uint32_t h[]) {    //compress block512

        for (RIPEMD::block512 p : blocks) {
            uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
            uint32_t aa = h[4], bb = h[5], cc = h[6], dd = h[7];

            //start iterating
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
    //get string, return hash message
    static void run(const string &str, uint32_t message[8]) {

        for (int i = 0; i < 8; i++) {   //initialize message
            message[i] = RIPEMD::iniNumber[i];
        }
        compress(expand(str), message); //expand the string, then compress

//        for (int i = 0; i < 8; i++) {
//            cout << message[i] << endl;
//        }
//        cout << endl;
    }
};


#endif //GOST_RIPEMD256_H
