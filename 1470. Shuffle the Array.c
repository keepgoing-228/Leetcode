/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* resortingArray;
    resortingArray = (int *)malloc(sizeof(int)* numsSize);
    *returnSize = numsSize;
    
    int i;
    for(i = 0; i< numsSize;i = i+2){
        resortingArray[i]= nums[i/2];
        resortingArray[i+1] = nums[n+i/2];
    }
    
    return resortingArray;
}
