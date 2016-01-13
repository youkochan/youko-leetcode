/**
 * Power of Three
 * https://leetcode.com/problems/power-of-three/
 */

/*
 * Given an integer, write a function to determine if it is a power of three.
 * If log10(n) / log10(3) returns an int
 * (more precisely, a double but has 0 after decimal point),
 * then n is a power of 3. (original post). But be careful here,
 * you cannot use log (natural log) here, because it will generate round off error for n=243.
 * This is more like a coincidence. I mean when n=243, we have the following results:

 * log(243) = 5.493061443340548    log(3) = 1.0986122886681098
   ==> log(243)/log(3) = 4.999999999999999
 * log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
   ==> log10(243)/log10(3) = 5.0
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 不能使用 log
        double r = (double)log10(n) / log10(3);
        return  r - int(r) == 0;
    }
};

int main() {
    Solution s;
    if (s.isPowerOfThree(243))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
