// Find Minimum in Rotated Sorted Array
// Find Minimum in Rotated Sorted Array Total Accepted: 36784 Total Submissions: 111742 My Submissions Question Solution 
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// You may assume no duplicate exists in the array.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int findMin(int num[], int n) {
    int left = 0;
    int right = n - 1;
    int direct1;    // 0 向上
    int direct2;    // 1 向下
    int mid;
    
    if(n == 1)
        return num[0];
    if(n == 2)
        return num[0] < num[1] ? num[0] : num[1];
    
    while(left < right){
        mid = (left + right) >> 1;
        
        direct1 = num[mid-1] < num[mid] ? 0 : 1;
        direct2 = num[mid+1] > num[mid] ? 0 : 1;

        if(!direct1 && direct2){
            return num[mid-1] < num[mid+1] ? num[mid-1] : num[mid+1];
        }
        else if(direct1 && !direct2){
            return num[mid];
        }
        else if(!direct1 && !direct2){
            if(num[mid] > num[right]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        else{
            if(num[mid] < num[right]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
    }
    
    return num[left];
}

int main(){
	int nums[] = {1, 4, 3, 2};
	printf("%d\n", findMin(nums, 4));
    return 0;
}