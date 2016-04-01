#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a = 0x12345678;
    char *c = (char*)&a;

    cout << int(*(c+0)) << endl;
    cout << int(*(c+1)) << endl;
    cout << int(*(c+2)) << endl;
    cout << int(*(c+3)) << endl;

    cout << *(c+0) << endl;
    cout << *(c+1) << endl;
    cout << *(c+2) << endl;
    cout << *(c+3) << endl;

    return 0;
}
