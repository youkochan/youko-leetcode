#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int titleToNumber(char *s) {
	int i = 0;
	int num = 0;

	while(s[i] != '\0'){
		num *= 26;
		num += s[i] - 'A' + 1;
		i ++;
	}

	return num;
}

int main(){
    printf("%d\n", titleToNumber("A"));
    return 0;
}