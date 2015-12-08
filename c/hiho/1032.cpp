#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n-- > 0) {
        string s, buf;
        cin >> s;
        int id = 0;
        int mx = 0;
        buf = "$#";
        for (int i = 0; s[i] != '\0'; i ++) {
            buf += s[i];
            buf += '#';
        }
        //cout << buf << endl;
        int* p = new int[buf.size()];
        for (int i = 1; buf[i] != '\0'; i ++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (buf[i + p[i]] == buf[i - p[i]]) {
                p[i] ++;
                //cout << i << ":" << p[i] << endl;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        int max = 0;
        for (int i = 1; i < buf.size(); i ++) {
            //cout << p[i] << " ";
            if (p[i] > max)
                max = p[i];
        }
        //cout << endl;
        cout << max - 1 << endl;
    }
    return 0;
}
