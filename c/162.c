// A peak element is an element that is greater than its neighbors.
// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that num[-1] = num[n] = -∞.
// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
// click to show spoilers.

// Note:
// Your solution should be in logarithmic complexity.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int findPeakElement(int num[], int n) {
	int left = 0;
	int right = n - 1;
	int mid;
	int up;
	int down;

	while(left < right){
		mid = (left + right) >> 1;

		up = ((mid-1) == -1 || num[mid] > num[mid-1]) ? 1 : 0;
		down = ((mid+1) == n || num[mid] > num[mid+1]) ? 1 : 0;

		if(up && down){
			return mid;
		}
		else if(up && !down){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}

	return left;
}

int main(){
	int nums[] = {1, 2, 3, 1};
	printf("%d\n", findPeakElement(nums, 1));
	return 0;
}