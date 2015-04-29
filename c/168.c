#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *convertToTitle(int n) {
    int mod;
    int div;
    int i1 = 0, i2 = 0;
    char* p1 = NULL;
    char* p2 = NULL;
    
    p1 = (char*)malloc(sizeof(char)*100);
    p2 = (char*)malloc(sizeof(char)*100);

    mod = n % 27;
    div = n / 27;

    while(mod != 0 || div != 0){
        p1[i1++] = mod + 'A' - 1;

        n = div;
        mod = n % 27;
        div = n / 27;
    }

    for(i2 = 0; i2 <= i1-1; i2++){
        p2[i2] = p1[i1-i2-1];
    }
    p2[i2] = '\0';

    return p2;
}

int main(){
    printf("%s\n", convertToTitle(27));
    return 0;
}