// Spiral Matrix II Total Accepted: 26246 Total Submissions: 83100 My Submissions Question Solution 
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <stdio.h>
#include <stdlib.h>

int **generateMatrix(int n) {
    int** matrix = NULL;
    int i = 0, j = 0;
    int count = 0;
    int total = n * n;
    int top = 0;
    int right = n - 1;
    int left = 0;
    int bottom = n - 1;

    matrix = (int**)malloc(sizeof(int*)*n);
    for(i=0; i<=n-1; i++) {
    	matrix[i] = (int*)malloc(sizeof(int)*n);
    }

    i = j = 0;

    while(count < total){
        while(j <= right && count < total){ count++; matrix[i][j] = count; j++;}
        top ++;
        j--;
        i++;
        while(i <= bottom && count < total){ count++; matrix[i][j] = count; i++;}
        right --;
        i--;
        j--;
        while(j >= left && count < total){ count++; matrix[i][j] = count; j--;}
        bottom --;
        j++;
        i--;
        while(i >= top && count < total){ count++; matrix[i][j] = count; i--;}
        left ++;
        i++;
        j++;
    }

    return matrix;
}

int main() {
    int n = 3;
    int i, j;
    int**matrix = NULL;

    matrix = generateMatrix(n);

    for(i = 0; i<=n-1; i++) {
    	for(j = 0; j<=n-1; j++){
    		printf("%d ", matrix[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}
