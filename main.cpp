#include <bits/stdc++.h>

#include "Algorithm/ripemd256.h"
#include "Algorithm/gostDemo.h"
#include "EncryptDecrypt.h"

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

    string x = "This is a test.";
    string key = "233";
    string res0 = EncryptDecrypt::run(x, key, 0, true);
    string res1 = EncryptDecrypt::run(x, key, 1, true);
    string res2 = EncryptDecrypt::run(x, key, 2, true);
    string res3 = EncryptDecrypt::run(x, key, 3, true);
    string res4 = EncryptDecrypt::run(x, key, 4, true);

    cout << res0 << ' ' << EncryptDecrypt::run(res0, key, 0, false) << endl;
    cout << res1 << ' ' << EncryptDecrypt::run(res1, key, 1, false) << endl;
    cout << res2 << ' ' << EncryptDecrypt::run(res2, key, 2, false) << endl;
    cout << res3 << ' ' << EncryptDecrypt::run(res3, key, 3, false) << endl;
    cout << res4 << ' ' << EncryptDecrypt::run(res4, key, 4, false) << endl;
}

void fileTest() {   //need to read & write file in binary mode

    string x = "../233.txt", y = "../Sugar.mp3";
    string key = "key";
    EncryptDecrypt::run(x, key, 0, true, "asfd");
    EncryptDecrypt::run(x, key, 0, false, "asfdfasf");
//    EncryptDecrypt::run(y, key, 0, true, 1);
//    EncryptDecrypt::run(y, key, 0, false, 1.1);
}

//text, key, mode, isEncrypt
//FILE, key, mode, isEncrypt, anything
int main(int argc, char * argv[]) {

//    ripemdTest();
//    gostDemoTest();
//    blockCipherTest();
    fileTest();

    return 0;
}
