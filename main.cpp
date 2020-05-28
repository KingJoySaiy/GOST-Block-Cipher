#include <bits/stdc++.h>
#include "Interface/EncryptDecrypt.h"
#include "Test/test.h"

using namespace std;

int main(int argc, char *argv[]) {

//    fileTest();
    string select, text, key, mode;
    while (true) {
        cout << "select operation: 0(encrypt string), 1(encrypt file), " << endl;
        cout << "                  2(decrypt string), 3(decrypt file), other(end)" << endl;
        getline(cin, select);
        if (select.compare("0") and select.compare("1") and select.compare("2") and select.compare("3")) {
            break;
        }

        cout << "input text/file-path: ";
        getline(cin, text);
        cout << "input key: ";
        getline(cin, key);
        cout << "input mode(0:ECB, 1:CBC, 2:CFB, 3:OFB, 4:CTR): ";
        getline(cin, mode);
        cout << "result: ";

        //used to calculate run-time
//		clock_t start = clock(), end;

        try {
            cout << EncryptDecrypt::run(text, key, mode, atoi(select.c_str()) & 2, atoi(select.c_str()) & 1) << endl;
        } catch (const char *error) {
            cout << error << endl;
        }

//        end = clock();
//        cout << "The run time is:" <<(double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;

    }

    return 0;
}
