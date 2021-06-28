
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize){
    int i, index, counts;
    *returnSize = numsSize;
    int *output = malloc((*returnSize)*sizeof(int));
    for(i = 0; i < numsSize; i++){
        counts = 0;
        for(index = 0;index < numsSize;index ++){
            if((i != index) && (nums[i]>nums[index])){
                counts++;
            }
        }
        
        output[i]= counts;
    }
    
    return output;
    free(output);
}
