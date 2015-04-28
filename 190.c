#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
	uint32_t count = 0;
	uint32_t hbit = 1;
	uint32_t lbit = 1;
	uint32_t result = 0;
	uint32_t temp = 0;

	hbit <<= 31;

	while(count++ <= 32){
		temp = n & lbit;
		if(temp!=0){
			result |= hbit;
		}
		lbit <<= 1;
		hbit >>= 1;
	}
	return result;
}

uint32_t main(){
	uint32_t num = 43261596;
	uint32_t result = 0;

	result = reverseBits(num);
	printf("%d\n", result);

	return 0;
}
