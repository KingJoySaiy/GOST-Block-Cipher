//
// Created by Joy on 2020/4/30.
//

#ifndef GOST_CONST_H
#define GOST_CONST_H

#include <iostream>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using std::pair;
using std::make_pair;
using std::swap;
using std::vector;
using std::string;

typedef unsigned char uint4_t;

//cyclically rotates x over n bits to the left
#define rol(x, n) (((x) << (n)) | ((x) >> (32-(n))))

//add a and b (module 2^32)
#define add(a, b) (1ULL * a + b) % (1ULL << 32)

/******** constants of RIPEMD-256 ********/
namespace RIPEMD {

    //initial message
    const uint32_t iniNumber[] = {0x67452301U, 0xEFCDAB89U, 0x98BADCFEU, 0x10325476U,
                                  0x76543210U, 0xFEDCBA98U, 0x89ABCDEFU, 0x01234567U};

    //round 1-4
    const uint32_t r[] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
            7, 4, 13, 1, 10, 6, 15, 3, 12, 0, 9, 5, 2, 14, 11, 8,
            3, 10, 14, 4, 9, 15, 8, 1, 2, 7, 0, 6, 13, 11, 5, 12,
            1, 9, 11, 10, 0, 8, 12, 4, 13, 3, 7, 15, 14, 5, 6, 2,
    };

    //parallel round 1-4
    const uint32_t rr[]{
            5, 14, 7, 0, 9, 2, 11, 4, 13, 6, 15, 8, 1, 10, 3, 12,
            6, 11, 3, 7, 0, 13, 5, 10, 14, 15, 8, 12, 4, 9, 1, 2,
            15, 5, 1, 3, 7, 14, 6, 9, 11, 8, 12, 2, 10, 0, 4, 13,
            8, 6, 4, 1, 3, 11, 15, 0, 5, 12, 2, 13, 9, 7, 10, 14
    };

    //cyclically rotates x over S[j] bits to the left
    //round 1-4
    inline uint32_t rol_s(uint32_t x, uint32_t j) {
        static const uint32_t S[] = {
                11, 14, 15, 12, 5, 8, 7, 9, 11, 13, 14, 15, 6, 7, 9, 8,
                7, 6, 8, 13, 11, 9, 7, 15, 7, 12, 15, 9, 11, 7, 13, 12,
                11, 13, 6, 7, 14, 9, 13, 15, 14, 8, 13, 6, 5, 12, 7, 5,
                11, 12, 14, 15, 14, 15, 9, 8, 9, 14, 5, 6, 8, 6, 5, 12
        };
        return rol(x, S[j]);
    }

    //cyclically rotates x over SS[j] bits to the left
    //parallel round 1-4
    inline uint32_t rol_ss(uint32_t x, uint32_t j) {
        static const uint32_t SS[] = {
                8, 9, 9, 11, 13, 15, 15, 5, 7, 7, 8, 11, 14, 14, 12, 6,
                9, 13, 15, 7, 12, 8, 9, 11, 7, 7, 12, 7, 6, 15, 13, 11,
                9, 7, 15, 11, 8, 6, 6, 14, 12, 13, 5, 14, 13, 13, 7, 5,
                15, 5, 8, 11, 14, 14, 6, 14, 6, 9, 12, 9, 12, 5, 15, 8
        };
        return rol(x, SS[j]);
    }

    uint32_t f(uint32_t j, uint32_t x, uint32_t y, uint32_t z) { //basic function
        if (j <= 15) return (x ^ y ^ z);
        else if (j <= 31) return ((x & y) | ((~x) & z));
        else if (j <= 47) return ((x | (~y)) ^ z);
        else return ((x & z) | (y & (~z)));
    }

    uint32_t k(uint32_t j) {
        if (j <= 15) return 0x00000000U;
        else if (j <= 31) return 0x5A827999U;
        else if (j <= 47) return 0x6ED9EBA1U;
        else return 0x8F1BBCDCU;
    }

    uint32_t kk(uint32_t j) {
        if (j <= 15) return 0x50A28BE6U;
        else if (j <= 31) return 0x5C4DD124U;
        else if (j <= 47) return 0x6D703EF3U;
        else return 0x00000000U;
    }

    struct block512 {
        uint32_t x[16];

        block512() {
            memset(x, 0, sizeof(x));
        }
    };
}


/******** constants of RIPEMD-256 (end)********/








/******** constants of GOST algorithm ********/
namespace GOST {
    static const uint4_t sBoxConst[][16] = {
            12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1,
            6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15,
            11, 3, 5, 8, 2, 15, 10, 13, 13, 1, 7, 4, 12, 9, 6, 0,
            12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11,
            7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12,
            5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0,
            8, 14, 2, 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7,
            1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12, 11, 2
    };
}
/******** constants of GOST algorithm (end)********/

#endif //GOST_CONST_H
