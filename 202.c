#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getNum(int n) {
    int div, mod;
    int sum = 0;
    
    mod = n % 10;
    div = n / 10;
    
    while(mod != 0 || div != 0) {
        sum += mod * mod;
        
        n = div;
        mod = n % 10;
        div = n / 10;
    }
    
    return sum;
}


bool isHappy(int n) {
    int hash[2000] = {0};
    int num = n;
    int i = 0;

    if(n == 1)
    	return true;

    // 虽然后面计算getNum后num的值不会大于2000（甚至更小），但是第一次的n可能会很大，
   	// 为了防止越界，需要先进行一次getNum
   	num = getNum(n);

    for(i = 0; i < 2000; ++i) {
    	hash[i] = 0;
    }

    while(hash[num] == 0) {
        if(num == 1) {
            return true;
        }
        
        hash[num] = 1;
        num = getNum(num);
    }
    
    return false;
}


int main() {
    if(isHappy(10598542))
    	printf("Yes\n");
    else
    	printf("No\n");

    return 0;
}