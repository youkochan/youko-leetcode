#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int a1, int a2) {
    return a1 < a2 ? a1 : a2;
}

void init(int a[], int n){
    int i = 0;

    for(i = 0; i <= n - 1; i++)
        a[i] = 0;
}

char* longestPalindrome(char* s) {
    char str[2003];
    char*result = NULL;
    int p[2003];
    int pos1 = 0, pos2 = 0;
    int flag = 1;
    int i;
    int mx = 0, id = 0;
    int max_val = 0;
    int max_pos = 0;
    
    init(p, 2003);
    
    // 构造str
    for(pos1 = 0; s[pos1] != '\0'; pos1 ++) {
        if(pos1 == 0) {
            str[pos2++] = '$';
            str[pos2++] = '#';
        }
        str[pos2++] = s[pos1];
        str[pos2++] = '#';
    }
    str[pos2] = '\0';
    
    for(i = 1; str[i] != '\0'; i ++) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        
        while(str[i - p[i]] == str[i + p[i]]){ p[i] ++; }
        
        if(max_val < p[i]){
            max_val = p[i];
            max_pos = i;
        }
        
        if(i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }

    result = (char*)malloc(sizeof(char)*max_val);

    pos2 = 0;
    flag = 1;
    
    // 得到结果
    for(i = max_pos - max_val + 1; i <= max_pos + max_val - 1; i++ ) {
        if(!flag) {
            result[pos2++] = str[i];
        }
        flag = !flag;
    }
    result[pos2] = '\0';

    return result;
}

int main(){

    printf("%s\n", longestPalindrome("12345432123"));

    return 0;
}