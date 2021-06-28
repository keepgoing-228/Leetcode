#include<stdio.h>

int* processQueries(int* queries, int queriesSize, int m, int* returnSize){
    int *p = malloc(m*sizeof(int));
    int *result = malloc(queriesSize* sizeof(int));
    for(int i = 0 ; i < m ;i++){
        p[i] = i+1;
    }
    
    for(int j = 0 ; j < queriesSize ; j++){
        result[j] = findIndex(*(queries+j), m, p);
        permutation(result[j], p);
    }

    for(int k = 0; k < queriesSize; k++){
        *(returnSize+ k) =  *(result+ k);
    }
    
    free(p);
    return returnSize;
}

int findIndex(int value , int m , int* p){
    int i = 0;
    while(i < m && *(p+i) != value){
        i++;
    }
    return i;
}

void permutation(int index, int* p){
    int temp = *(p + index);
    for(int k = 0 ; k < index+1 ; k++){
        swap(&temp, p + k);
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int n, int *array){
    for(int i = 0; i < n ; i++){
        printf("%d ",*(array+i));
    }
}

int main(){
    int queries[4] = {3,1,2,1};
    int m = 5;
    int* result;
    result = processQueries(queries, 4,m ,result);
    print_array(4, result);
    // print_array(4, queries);

}