#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int singleNumber(int A[], int n) {
    while(--n > 0){
        A[0] ^= A[n];
    }
    
    return A[0];
}

int main(){
	int num[] = {0, 1, 1, 2, 2, 0, 6};
	printf("%d\n", singleNumber(num, 7));
    return 0;
}

