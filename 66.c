#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int*result = NULL;
    int f = 1;
    int c = 1;
    int sum = 0;
    int mod = 0, div = 0;
    
    result = (int*)malloc(sizeof(int)*(digitsSize+1));
    
    for(i = digitsSize - 1; i >= 0; i --) {
        sum = c + digits[i];
        
        if(sum != 10) {
            f = 0;
            result[i+1] = sum;
            c = 0;
        }
        else {
            result[i+1] = 0;
        }
    }
    
    if(f) {
        result[0] = 1;
        (*returnSize) = digitsSize + 1;
        return result;
    }
    else {
        (*returnSize) = digitsSize;

        return &(result[1]);
    }
}


int main() {
    int num[] = {9, 9, 9};
    int*tmp = NULL;
    int size = 0;
    int i;

    tmp = plusOne(num, 3, &size);

    for(i = 0; i <= size-1; i++) {
        printf("%d ", tmp[i]);
    }

    return 0;
}