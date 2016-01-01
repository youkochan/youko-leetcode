/**
 * title
 * url
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

template<typename T>
string ntos(T n) {
    ostringstream os;
    os << n;
    return os.str();
}

template<typename T>
T ston(string s) {
    istringstream ss(s);
    T n;
    ss >> n;
    return n;
}

int main() {
    int i = 99;
    double d = 9.21;

    cout << ntos(i) << endl;
    cout << ntos(d) << endl;
    cout << ston<int>("12345") << endl;
    cout << ston<double>("12121.2") << endl;

    return 0;
}
