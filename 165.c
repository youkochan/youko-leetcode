#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int compareVersion(char *version1, char *version2){
    int v1 = 0, pos1 = 0;
    int v2 = 0, pos2 = 0;
    int f1 = 0, f2 = 0;
    int i = 0;
    
    while(!f1 || !f2){
        v1 = 0;
        if (!f1){
            for(i=pos1; version1[i]!='\0'; i++){
                if(version1[i] == '.'){
                    pos1 = i + 1;
                    break;
                }
                else{
                    v1 = v1 * 10 + version1[i] - '0';
                }
            }
        }
        if(version1[i]=='\0')
            f1 = 1;

        v2 = 0;
        if (!f2){
            for(i=pos2; version2[i]!='\0'; i++){
                if(version2[i] == '.'){
                    pos2 = i + 1;
                    break;
                }
                else{
                    v2 = v2 * 10 + version2[i] - '0';
                }
            }
        }
        if(version2[i]=='\0')
            f2 = 1;

        printf("%d\n", v1);
        printf("%d\n", v2);

        if (v1 > v2)
            return 1;
        else if(v1 < v2)
            return -1;
    }

    return 0;
}


int main(){
    printf("%d\n", compareVersion("1", "1.1"));
    return 0;
}