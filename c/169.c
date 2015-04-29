#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int majorityElement(int num[], int n) {
    int maj, count = 0;
    int i = 0;
    
    for (i=0; i<=n-1; i++){
        if (count == 0){
            maj = num[i];
            count = 1;
        }
        else{
            if (num[i] == maj){
                count ++;
            }
            else{
                count --;
            }
        }
    }
    
    return maj;
}

int main(){
    int prices[] = {2, 1, 2, 2};

    printf("%d\n", majorityElement(prices, 4));
    return 0;
}