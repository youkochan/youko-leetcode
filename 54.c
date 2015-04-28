#include <stdio.h>
#include <stdlib.h>

int *spiralOrder(int numRows, int numColumns) {
    int matrix[2][1] = {{1}, {2}};

    int* result = NULL;
    int top = 0;
    int right = numColumns - 1;
    int left = 0;
    int bottom = numRows - 1;
    int count = 0;
    int total = numRows * numColumns;
    int i = 0, j = 0;
    
    result = (int*)malloc(sizeof(int) * total);

    while(count < total){
        while(j <= right && count < total){ result[count] = matrix[i][j]; printf("%d %d\n", i, j); count++; j++;}
        top ++;
        j--;
        i++;
        while(i <= bottom && count < total){ result[count] = matrix[i][j]; printf("%d %d\n", i, j); count++; i++;}
        right --;
        i--;
        j--;
        while(j >= left && count < total){ result[count] = matrix[i][j]; printf("%d %d\n", i, j); count++; j--;}
        bottom --;
        j++;
        i--;
        while(i >= top && count < total){ result[count] = matrix[i][j]; printf("%d %d\n", i, j); count++; i--;}
        left ++;
        i++;
        j++;
    }
    
    return result;
}


int main(){
    int*res = NULL;
    int i = 0;

    res = spiralOrder(2, 1);

    for(i = 0; i<=1; i++){
        printf("%d\n", res[i]);
    }

    return 0;
}