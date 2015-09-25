#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
        
    int flag = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    int res = 0;
    
    long long ldividend = labs(dividend);
    long long ldivisor  = labs(divisor);
    unsigned int time = 1;

    while((ldivisor << 1) <= ldividend) {
        ldivisor <<= 1;
        time <<= 1;
    }

    // cout << oct << ldivisor << endl;
    // cout << oct << time << endl;
    
    while(time >= 1) {
        if(ldividend >= ldivisor) {
            ldividend -= ldivisor;
            res += time;
        }
        ldivisor >>= 1;
        time >>= 1;
    }
    
    return res * flag;
}

int main() {
	int n1 = -2147483648;
	int n2 = 1;

	cout << divide(n1, n2) << endl;

	return 0;
}
