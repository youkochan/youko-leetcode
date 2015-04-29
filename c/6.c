#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int nRows) {
    char* l = NULL;
    int i = 0;
    int size = strlen(s);
    int pos1 = 0;
    int pos2 = 0;
    int flag = 0;

    l = (char*)malloc(sizeof(char)*(size+1));

    if(nRows == 1){
        for(i = 0; i <= size-1; i++)
            l[i] = s[i];
        l[i] = '\0';

        return l;
    }

    for(i = 0; i <= nRows-1; i++) {
        pos1 = i;
        if(i == 0 || i == nRows-1){
            while(pos1 <= size - 1) {
                l[pos2++] = s[pos1];
                pos1 = pos1 + 2*(nRows - 1);
            }
        }
        else{
            flag = 1;
            while(pos1 <= size - 1) {
                l[pos2++] = s[pos1];
                pos1 += flag ? 2 * (nRows - i - 1) : 2 * i;
                flag = !flag;
            }
        }
    }

    l[pos2] = '\0';

    return l;
}

int main() {
    char*s = "ABB";

    printf("%s\n", convert(s, 1));

    return 0;
}
