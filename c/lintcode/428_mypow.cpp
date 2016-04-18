class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (!(n % 2)) {
            double temp = myPow(x, n / 2);
            return temp * temp;
        }
        else {
            double temp = myPow(x, n / 2);
            return temp * temp * x;
        }
    }
};
