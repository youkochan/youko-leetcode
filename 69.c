// Implement int sqrt(int x).

// Compute and return the square root of x.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int mySqrt(int x) {
    double x0, x1, diff;

    if (x == 0)
        return 0;

    x1 = x;
    do{
        x0 = x1;
        x1 = ((double)x / x0 + x0) / 2;
        diff = abs(x1 - x0);
    }
    while ( diff > 0.001 );
    
    return (int)x1;
}

int main(){
    printf("%d\n", mySqrt(0));
    return 0;
}