#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 */

int max(int n1, int n2){
	return n1 > n2 ? n1 : n2;
}

int** getMatrix(int n, int k){
    int i = 0, j = 0;
    int** p = NULL;

    p = (int**)malloc(sizeof(int*)*n);
    for (i = 0; i <= n-1; i++){
        p[i] = (int*)malloc(sizeof(int)*k);

        for (j = 0; j <= k-1; j ++){
            p[i][j] = 0;
        }
    }
    return p;
}

void freeMatrix(int** p, int n){
    int i = 0;

    for (i = 0; i<= n-1; i++){
        free(p[i]);
    }
    free(p);
}

int simpleMaxProfit(int prices[], int n){
    int i = 0;
    int max = 0;
    int d = 0;
    
    if(n == 1)
        return 0;
    
    for(i = 1; i <= n - 1; i++){
        d = prices[i] - prices[i-1];
        if(d > 0)
            max += d;
    }
    
    return max;
}

int maxProfit(int k, int prices[], int n)
{
    int** g = NULL;
    int** l = NULL;
    int i = 0;
    int j = 0;
    int diff = 0;

    if(n == 1)
        return 0;
    if(k >= n / 2)
        return simpleMaxProfit(prices, n);

    g = getMatrix(n, k+1);
    l = getMatrix(n, k+1);

    for (i = 1; i<= n-1; i++){
        diff = prices[i] - prices[i-1];
        for (j = 1; j <= k; j ++){
            l[i][j] = max(g[i-1][j-1] + max(diff, 0), l[i-1][j]+diff);
            g[i][j] = max(g[i-1][j], l[i][j]);
        }
    }

    // freeMatrix(g, n);
    // freeMatrix(l, n);

    return g[n-1][k];
}


int main(){
	int prices[] = {1, 2, 4, 1, 9};

	printf("%d\n", maxProfit(2, prices, 5));
	return 0;
}