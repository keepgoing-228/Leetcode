

int minPairSum(int* nums, int numsSize){
    int pairNums = (numsSize/2);
    int ans;
    int* p = malloc(pairNums*sizeof(int));
    bubble_sorts(nums, numsSize);
    for(int i = 0; i < pairNums; i++){
        *(p+i) = *(nums+i) + *(nums+(numsSize-1-i));
    }
    
    ans = *p;
    
    for(int i = 0; i < pairNums; i++){
        if(ans < *(p+i))
            ans = *(p+i);
    }
    
    return ans;
}

void swap(int *smallest, int *first_element){
    int middle;
    middle = *smallest;
    *smallest = *first_element;
    *first_element = middle;
}

void bubble_sorts(int* list, int num_in_list){
    int i,j;
    for(i = num_in_list-1; i>0; i--){
        for(j = 0; j< i; j++){
            if (*(list+i) < *(list+j)){
                swap((list+i),(list+j));
            }
        }
    }
}