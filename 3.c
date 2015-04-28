#include <stdio.h>

// 出现重复字符时，从该重复字符的上一次出现位置index加一处继续查找

void resetHash(int hash[]) {
    int i;
    
    for(i = 0; i <= 255; i++) {
        hash[i] = -1;
    }
}

int lengthOfLongestSubstring(char* s) {
    int hash[256];
    int i   = 0;
    int len = 0;
    int max = 0;
    
    resetHash(hash);
    
    while(s[i] != '\0') {


        if(hash[s[i]] != -1) {
            i = hash[s[i]] + 1;
            len = 0;
            resetHash(hash);
        }
        else {
            hash[s[i]] = i;
            len ++;
            i++;
            
            max = len > max ? len : max;
        }
    }
    
    return max;
}

int main() {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));

    return 0;
}