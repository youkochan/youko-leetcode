#include <stdio.h>
#include <stdint.h>

// Best Time to Buy and Sell Stock 1

int maxProfit(int prices[], int n){
    int l = 0;
    int h = n - 1;
    int max = 0;
    int min = 0;

    while(l <= h){
    	if(prices[h] > max)
    		max = prices[h];
    	if(prices[l] < min || !min)
    		min = prices[l];
    	h --;
    	l ++;
    }

    if (max - min > 0)
    	return max - min;
    else
    	return 0;
}

int main(){
	int prices[] = {1, 1, 1, 1, 1, 1};

	printf("%d\n", maxProfit(prices, 6));
	return 0;
}
