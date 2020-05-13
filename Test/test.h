#ifndef GOST_TEST_H
#define GOST_TEST_H

#include <bits/stdc++.h>

#include "../Algorithm/ripemd256.h"
#include "../Algorithm/gostDemo.h"
#include "../Interface/EncryptDecrypt.h"

using namespace std;

void ripemdTest() { //almost ok

    string x = "";
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

void blockCipherTest() {    //ok

    string x = "this is a test";
    string key = "233";
    string res0 = EncryptDecrypt::run(x, key, "0", false, false);
    string res1 = EncryptDecrypt::run(x, key, "1", false, false);
    string res2 = EncryptDecrypt::run(x, key, "2", false, false);
    string res3 = EncryptDecrypt::run(x, key, "3", false, false);
    string res4 = EncryptDecrypt::run(x, key, "4", false, false);

    cout << res0 << ' ' << EncryptDecrypt::run(res0, key, "0", true, false) << endl;
    cout << res1 << ' ' << EncryptDecrypt::run(res1, key, "1", true, false) << endl;
    cout << res2 << ' ' << EncryptDecrypt::run(res2, key, "2", true, false) << endl;
    cout << res3 << ' ' << EncryptDecrypt::run(res3, key, "3", true, false) << endl;
    cout << res4 << ' ' << EncryptDecrypt::run(res4, key, "4", true, false) << endl;
}

void fileTest() {   //need to read & write file in binary mode

    string x = "../233.txt", y = "../Sugar.mp3";
    string key = "key";
//    cout << EncryptDecrypt::run(x, key, "0", false, true) << endl;
    cout << EncryptDecrypt::run(x, key, "0", true, true) << endl;

//    EncryptDecrypt::run(y, key, 0, true, 1);
//    EncryptDecrypt::run(y, key, 0, false, 1.1);
}

void specialTest() {

    string x = "asoinfu124", key = "233";
    string goodPath = "../233.txt", badPath = "test.txt";
//    cout << EncryptDecrypt::run(x, key, "1", true, false) << endl;
//    cout << EncryptDecrypt::run(goodPath, key, "2", true, true) << endl;
//    cout << EncryptDecrypt::run(badPath, key, "3", false, true) << endl;
//    cout << EncryptDecrypt::run("166cf3f52702055c", "", "1", true, false) << endl;
    cout << EncryptDecrypt::run("", "", "0", true, false) << endl;
}


#endif //GOST_TEST_H









