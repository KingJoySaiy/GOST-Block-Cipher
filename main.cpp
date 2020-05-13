#include <bits/stdc++.h>
#include "Test/test.h"

using namespace std;

int main(int argc, char *argv[]) {

//    blockCipherTest();

    string select, text, key, mode;
    while (true) {
        puts("0(encrypt string), 1(encrypt file), 2(decrypt string), 3(decrypt file), other(break)");
        cin >> select;
        if (select.compare("0") and select.compare("1") and select.compare("2") and select.compare("3")) {
            break;
        }

        cout << "input " << ((!mode.compare("0") or !mode.compare("2")) ? "text" : "file-path") << ", key & mode: ";
        cin >> text >> key >> mode;
        cout << "result: ";

        try {
            cout << EncryptDecrypt::run(text, key, mode, atoi(select.c_str()) & 2, atoi(select.c_str()) & 1) << endl << endl;
        } catch (const char *error) {
            cout << error << endl;
        }
    }

    return 0;
}
