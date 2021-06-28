

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 int* processQueries(int* queries, int queriesSize, int m, int* returnSize){
    int *P = malloc(m*sizeof(int));
    int *ans = malloc(queriesSize*sizeof(int));
    *returnSize = queriesSize;
    
    for(int i=0;i<m;i++){
        P[i]=i+1;
    }
    for(int i=0;i<queriesSize;i++){
        for(int j=0;j<m;j++){
            if(queries[i]==P[j]){
                ans[i]=j;
                for(int k=j; k>0;k--){
                    P[k]=P[k-1];
                }
                P[0]=queries[i];
                break;
            }
        }
    }
    free(P);
    return ans;
}

// int* processQueries(int* queries, int queriesSize, int m, int* returnSize){
//     int *p = malloc(m*sizeof(int));
//     int *result = malloc(queriesSize* sizeof(int));
    
    
//     for(int i = 0 ; i < m ;i++){
//         p[i] = i+1;
//     }
    
//     for(int j = 0 ; j < queriesSize ; j++){
//         result[j] = findIndex(*(queries+j), m, p);
//         permutation(result[j], p);
//     }
    
//     for(int k = 0; k < queriesSize; k++){
//         *(returnSize + k) =  *(result+k);
//     }
    
//     free(p);
    
//     return result;
// }

// int findIndex(int value , int m , int* p){
//     int i = 0;
//     while(i < m && *(p+i) != value){
//         i++;
//     }
//     return i;
// }

// void permutation(int index, int* p){
//     int temp = *(p + index);
//     for(int k = 0 ; k < index+1 ; k++){
//         swap(&temp, p + k);
//     }
// }

// void swap(int *a, int *b){
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

