//#include <bits/stdc++.h>
//
//#include "Algorithm/ripemd256.h"
//#include "Algorithm/gostDemo.h"
//#include "EncryptDecrypt.h"
//
//using namespace std;
//
///*
//RIPEMD-256 mapping (padding method unknown)
//"" (empty string)	02ba4c4e5f8ecd1877fc52d64d30e37a2d9774fb1e5d026380ae0168e3c5522d
//"a"	f9333e45d857f5d90a91bab70a1eba0cfb1be4b0783c9acfcd883a9134692925
//"abc"	afbd6e228b9d8cbbcef5ca2d03e6dba10ac0bc7dcbe4680e1e42d2e975459b65
//*/
//
//void ripemdTest() { //need to check "padding method"
//
//    string x = "1234567890123456789012345678901234567890123456789012345678901234";
//    uint32_t message[8];
//
//    ripemd256::run(x, message);
//    for (int i = 0; i < 8; i++) {
//        printf("%x\n", message[i]);
//    }
//}
//
//void gostDemoTest() {   //ok
//
//    uint64_t x = 123;
//    string key = "233";
//    uint32_t message[8];
//    ripemd256::run(key, message);
//    cout << x << endl;
//
//    gostDemo::runEncrypt(x, message);
//    cout << x << endl;
//
//    gostDemo::runDecrypt(x, message);
//    cout << x << endl;
//}
//
//void blockCipherTest() {    //ok
//
//    string x = "This is a test.";
//    string key = "233";
//    string res0 = EncryptDecrypt::run(x, key, 0, true);
//    string res1 = EncryptDecrypt::run(x, key, 1, true);
//    string res2 = EncryptDecrypt::run(x, key, 2, true);
//    string res3 = EncryptDecrypt::run(x, key, 3, true);
//    string res4 = EncryptDecrypt::run(x, key, 4, true);
//
//    cout << res0 << ' ' << EncryptDecrypt::run(res0, key, 0, false) << endl;
//    cout << res1 << ' ' << EncryptDecrypt::run(res1, key, 1, false) << endl;
//    cout << res2 << ' ' << EncryptDecrypt::run(res2, key, 2, false) << endl;
//    cout << res3 << ' ' << EncryptDecrypt::run(res3, key, 3, false) << endl;
//    cout << res4 << ' ' << EncryptDecrypt::run(res4, key, 4, false) << endl;
//}
//
//int main() {
//
////    ripemdTest();
////    gostDemoTest();
//    blockCipherTest();
//
//    return 0;
//}
