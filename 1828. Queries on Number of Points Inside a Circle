/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    (*returnSize) = queriesSize;
    int* output = malloc((*returnSize)*sizeof(int));
    for(int i = 0; i < queriesSize ; i++){
        int count = 0;
        for (int j = 0; j < pointsSize; j++){
            if(isInside(points,pointsSize,pointsColSize,queries,queriesSize,queriesColSize, returnSize,i,j)){
            count++;
            }
        }
        *(output + i) = count;
        // output[i] = count;
    }
    return output;
}

int isInside(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int i, int j){
    int radius;
    double distancePow,distance;
    distancePow = pow((*(*(points+j)+0) - *(*(queries+i)+0)),2) + pow(*(*(points+j)+1) -*(*(queries+i)+1), 2);
    distance = sqrt(distancePow);
    radius = *(*(queries+i)+2);
    if(distance <= radius){
        return 1;
    }
    return 0;
}
