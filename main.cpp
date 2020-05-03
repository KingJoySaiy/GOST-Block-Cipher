#include <bits/stdc++.h>

#include "Algorithm/ripemd256.h"
#include "Algorithm/gostDemo.h"
#include "EncryptDecrypt.h"

using namespace std;

/*
RIPEMD-256 mapping (padding method unknown)
"" (empty string)	02ba4c4e5f8ecd1877fc52d64d30e37a2d9774fb1e5d026380ae0168e3c5522d
"a"	f9333e45d857f5d90a91bab70a1eba0cfb1be4b0783c9acfcd883a9134692925
"abc"	afbd6e228b9d8cbbcef5ca2d03e6dba10ac0bc7dcbe4680e1e42d2e975459b65
*/

void ripemdTest() { //need to check "padding method"

    string x = "1234567890123456789012345678901234567890123456789012345678901234";
    uint32_t message[8];

    ripemd256::run(x, message);
    for (int i = 0; i < 8; i++) {
        printf("%x\n", message[i]);
    }
}

void gostDemoTest() {   //ok

    uint64_t x = 123;
    string key = "233";
    uint32_t message[8];
    ripemd256::run(key, message);
    cout << x << endl;

    gostDemo::runEncrypt(x, message);
    cout << x << endl;

    gostDemo::runDecrypt(x, message);
    cout << x << endl;
}

void blockCipherTest() {    //ok: ECB, CBC

    string x = "test";
    string key = "233";
    string res1 = EncryptDecrypt::run(x, key, 0, true);
    string res2 = EncryptDecrypt::run(x, key, 1, true);

    cout << res1 << endl << EncryptDecrypt::run(res1, key, 0, false) << endl;
    cout << res2 << endl << EncryptDecrypt::run(res2, key, 1, false) << endl;
}

int main() {

//    ripemdTest();
//    gostDemoTest();
    blockCipherTest();

    return 0;
}
