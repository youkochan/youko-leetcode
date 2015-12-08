#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t1, t2, t3; // ¼ÇÂ¼¸öÊý
    int d[3];
    int t[3];
    int max = 0;
    int num = 0;
    t1 = t2 = t3 = 0;

    cin >> d[0] >> d[1] >> d[2];
    sort(d, d + 3);

    string s;
    cin >> s;


        for (int i = 0; i < s.size(); i ++) {
            num ++;
            if (num > max) {
                max = num;
            }
            if (s[i] == 'R')
                t1 ++;
            else if (s[i] == 'B') {
                t2 ++;
            }
            else {
                t3 ++;
            }
            t[0] = abs(t1 - t2);
            t[1] = abs(t3 - t2);
            t[2] = abs(t3 - t1);
            sort(t, t + 3);
            if (t[0] == d[0] &&
                t[1] == d[1] &&
                t[2] == d[2]) {
                t1 = t2 = t3 = 0;
                num = 0;
            }
        }

    cout << max << endl;
    return 0;

}
