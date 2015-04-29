// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct my_struct {
    int id;             // 原数组中的值
    int index;          // 原数组中的位置
    UT_hash_handle hh;
};

struct my_struct *hash_count = NULL;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int*   result = (int*)malloc(sizeof(int)*2);
    int    searchNum = 0;
    struct my_struct* newData = NULL;
    struct my_struct* oldData = NULL;
    int    i;
    int    id;
    
    (*returnSize) = 2;
    
    for(i = 0; i <= numsSize-1; i ++) {
        id = nums[i];
        oldData = NULL;
        
        HASH_FIND_INT(hash_count, &id, oldData);
        
        if(oldData == NULL) {
            newData = (struct my_struct*)malloc(sizeof(struct my_struct));
            newData->id = id;
            newData->index = i+1;
            HASH_ADD_INT(hash_count, id, newData);
        }
    }
    
    for(i = 0; i <= numsSize-1; i++) {
        searchNum = target - nums[i];
        oldData = NULL;
        
        HASH_FIND_INT(hash_count, &searchNum, oldData);
        
        if(oldData != NULL && oldData->index != i + 1) {
            result[0] = oldData->index < i + 1 ? oldData->index : i + 1;
            result[1] = oldData->index > i + 1 ? oldData->index : i + 1;
            break;
        }
    }
    
    return result;
}


int main() {
    int nums[] = {2,1,9,4,4,56,90,3};
    int*res = NULL;
    int returnSize = 0;

    res = twoSum((int*)nums, 8, 8, (int*)&returnSize);

    printf("%d, %d, %d\n", res[0], res[1], returnSize);

    return 0;
}

