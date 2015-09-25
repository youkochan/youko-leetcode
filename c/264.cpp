#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int min(int a, int b, int c){
        int minNum = a > b ? b : a;
        return minNum > c ? c : minNum;
    }
    
    int nthUglyNumber(int n) {
        int *ugly = new int[n];
        memset(ugly, 0, sizeof(int) * n);
        ugly[0] = 1;

        int factor2 = 2, factor3 = 3, factor5 = 5;
        int index2, index3, index5;
        index2 = index3 = index5 = 0;

        for(int i=1; i<n; i++){
            int minNum = min(factor2, factor3, factor5);
            ugly[i] = minNum;

            if(factor2 == minNum)
                 factor2 = 2 * ugly[++index2];
            if(factor3 == minNum)
                 factor3 = 3 * ugly[++index3];
            if(factor5 == minNum)
                 factor5 = 5 * ugly[++index5];

            // cout << factor2 << " " << factor3 << " " << factor5 << endl;
        }

        return ugly[n-1];
    }
};

int main() {
    Solution s;

    cout << s.nthUglyNumber(10) << endl;

    return 0;
}

