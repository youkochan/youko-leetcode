#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         for (int i = 0; i <= 31; i ++) {
             if ((n & (0x01 << i)) != 0)
                 count ++;
         }
         return count;
     }
};

int main() {
	//string a = "c(a,b)";

    //string::size_type lidx = a.find_first_of("(");
    //string::size_type midx = a.find_first_of(",");

    //cout << a.substr(lidx+1,midx-lidx-1) << endl;
    //cout << a.substr(midx+1,a.size()-midx-2) << endl;

    Solution s;
    cout << s.NumberOf1(1) << endl;

	return 0;
}
