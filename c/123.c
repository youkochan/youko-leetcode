/**
 * Best Time to Buy and Sell Stock III 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int max(int n1, int n2){
	return n1 > n2 ? n1 : n2;
}

int maxProfit(int prices[], int n)
{
    int* dp1;	// [0,...,i] 最大收益
    int* dp2;	// [i,...,n-1] 最大收益
    int maxprofit = 0;
    int i;
    int minPrice = prices[0];
    int maxPrice = prices[n-1];

    dp1 = (int*)malloc(sizeof(int)*n);
    dp2 = (int*)malloc(sizeof(int)*n);

    for (i = 0; i <= n-1; ++i){
    	dp1[i] = dp2[i] = 0;
    }

    if (n <= 1)
    	return 0;

    // 第一趟遍历找出dp1
    for (i = 1; i <= n-1; ++i){
    	if (minPrice > prices[i]){
    		minPrice = prices[i];
    	}
    	dp1[i] = max(dp1[i-1], prices[i]-minPrice);
    }

    // 第二趟遍历找出dp2
    for (i = n-2; i >= 0; --i){
    	if (maxPrice < prices[i]){
    		maxPrice = prices[i];
    	}
    	dp2[i] = max(dp2[i+1], maxPrice-prices[i]);
    }

    maxprofit = 0;

    // 最后找出最大收益
    for (i = 0; i <= n-1; ++i){
    	if (dp1[i] + dp2[i] > maxprofit)
    		maxprofit = dp1[i] + dp2[i];
    }

    free(dp1);
    free(dp2);

    return maxprofit;
}


int main(){
	int prices[] = {1, 2, 4};

	printf("%d\n", maxProfit(prices, 3));
	return 0;
}