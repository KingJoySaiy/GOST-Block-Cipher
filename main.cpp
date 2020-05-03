#include <iostream>
#include "Algorithm/ripemd256.h"

using namespace std;

/*
RIPEMD-256 mapping，64个16进制整数
"" (empty string)	02ba4c4e5f8ecd1877fc52d64d30e37a2d9774fb1e5d026380ae0168e3c5522d
"a"	f9333e45d857f5d90a91bab70a1eba0cfb1be4b0783c9acfcd883a9134692925
"abc"	afbd6e228b9d8cbbcef5ca2d03e6dba10ac0bc7dcbe4680e1e42d2e975459b65
*/

void ripemdTest() {

    string x = "1234567890123456789012345678901234567890123456789012345678901234";
    uint32_t message[8];

    ripemd256().run(x, message);
    for (int i = 0; i < 8; i++) {
        printf("%x\n", message[i]);
    }
}

int main() {

    ripemdTest();

    return 0;
}
