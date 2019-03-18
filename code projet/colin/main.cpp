#include <iostream>
#include "RS232.h"

using namespace std;

int main() {
    COM * rs;
    rs = new COM();

    bool test = rs->ouverture();
    if (test == TRUE)
    {
        cout << "hello world" << endl;
    }


    return 0;
}