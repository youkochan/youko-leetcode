#include <iostream>

// 无序数组的二分查找

using namespace std;

int sort(int* buf, int l, int r, int target) {
    if (l > r)
        return -1;
    int temp = buf[l];
    int pl = l;
    int pr = r;
    while (pl < pr) {
        while (pl < pr && buf[pr] > temp) {
            pr --;
        }
        buf[pl] = buf[pr];
        while (pl < pr && buf[pl] < temp) {
            pl ++;
        }
        buf[pr] = buf[pl];
    }
    buf[pl] = temp;
    /*
    for (int i = l; i <= r; i ++) {
        if (i == pl)
            cout << "[" << buf[i] << "]" << " ";
        else
            cout << buf[i] << " ";
    }
    cout << endl;
    */
    if (buf[pl] == target) {
        return pl;
    }
    else {
        if (target > buf[pl])
            return sort(buf, pl + 1, r, target);
        else
            return sort(buf, l, pl - 1, target);
    }
}

int main() {
    int n;
    int target;
    cin >> n >> target;

    int* buf = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> buf[i];
    }

    int result = sort(buf, 0, n-1, target);
    result == -1 ? cout << result << endl : cout << result + 1 << endl;
    return 0;
}
