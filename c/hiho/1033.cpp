#include <iostream>
#include <cstdlib>
#include <utility>
#include <map>

using namespace std;

pair<int, int> getVal(int num, map<int, pair<int, int> >& valMap) {
    if (valMap.find(num) != valMap.end()) {
        return valMap[num];
    }
    if (num < 10) {
        pair<int, int> result;
        result.first = num;
        result.second = -1;
        valMap[num] = result;
        return result;
    }
    int div = num / 10;
    int mod = num % 10;
    pair<int, int> result = getVal(div, valMap);
    result.first = result.first + result.second * mod;
    result.second = result.second * -1;
    valMap[num] = result;
    return result;
}

int main() {
    int l, r, k;
    int sum = 0;
    map<int, pair<int, int> > valMap;
    cin >> l >> r >> k;
    for (int i = l; i <= r; i ++) {
        if (getVal(i, valMap).first == k) {
            sum += i;
        }
    }
    cout << sum % 1000000007 << endl;
}
