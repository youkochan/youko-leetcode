#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int countPrimes(int n) {
    int  num = ceil(sqrt(n));
    int* hash = (int*)malloc(sizeof(int)*(n+1));
    int  i, j;
    int  count = 0;
    
    if(n == 0 || n == 1 || n == 2)
        return 0;
    
    for(i = 0; i <= n; i++) {
        hash[i] = 0;
    }
    
    for(i = 2; i <= n; i++) {
        j = 2 * i;
            
        for(; j <= n; j += i) {
            hash[j] = 1;
        }
    }
    
    for(i = 2; i <= n-1; i++) {
        if(hash[i] == 0) {
            count ++;
        }
    }
    
    return count;
}

int main() {
    printf("%d\n", countPrimes(5));

    return 0;
}