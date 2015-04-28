#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
	int count = 0;
	uint32_t i = 1;
	uint32_t temp = 0;
	int result = 0;

	while(count++<=32){
		temp = n & i;
		if(temp!=0)
			result++;
		i<<=1;
	}
	return result;
}

int main(){
	int num = 2;
	int result = 0;

	result = hammingWeight(num);
	printf("%d\n", result);

	return 0;
}
