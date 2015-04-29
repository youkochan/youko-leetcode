#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x) {
    int flag = x > 0 ? 1 : 0;
    int mod = 0;
    int div = 0;
    int sum = 0;
    
    mod = x % 10;
    div = x / 10;
    
    while(div != 0 || mod != 0){
        if(flag) {
            if(sum < 214748364 || (sum == 214748364 && mod <= 7))
                sum = sum * 10 + mod;
            else
                return 0;
        }
        else {
            if(sum > -214748364 || (sum == -214748364 && mod >= -8))
                sum = sum * 10 + mod;
            else
                return 0;
        }
        
        x = div;
        mod = x % 10;
        div = x / 10;
    }
    
    return sum;
}

int main(){

    printf("%d\n", reverse(-2147483648));

    return 0;
}