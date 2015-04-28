#include <stdio.h>
#include <stdint.h>

void rotate(int nums[], int n, int k) {
    int i = 0, pos1 = 0, pos2 = 0;
    int temp = 0;
    
    k %= n;

    for (i = 0; i <= (n - k) / 2 - 1; i ++){
        pos1 = i;
        pos2 = n - k - i - 1;

        temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }

    for (i = 0; i <= k / 2 - 1; i ++){
        pos1 = n - k + i;
        pos2 = n - 1 - i;

        temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }


    for (i = 0; i <= n / 2 - 1; i ++){
        pos1 = i;
        pos2 = n - 1 - i;

        temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }
}

int main(){
	int nums[] = {1, 2, 3, 4, 5, 6, 7};
	int i = 0;

	for (i = 0; i <= 6; i++){
		printf("%d\n", nums[i]);
	}

	printf("------\n");
	rotate(nums, 7, 8);

	for (i = 0; i <= 6; i++){
		printf("%d\n", nums[i]);
	}

	return 0;
}
