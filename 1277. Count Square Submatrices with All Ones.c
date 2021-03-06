int countSquares(int** matrix, int matrixSize, int* matrixColSize){

int count = 0;

for(int i = 0; i < matrixColSize[0]; i++) {
        count += matrix[0][i];
}
for(int i = 1; i < matrixSize; i++) {
         count += matrix[i][0];
}
    


for(int i = 1; i < matrixSize; i++) {
    for(int j = 1 ; j<matrixColSize[0]; j++ ) {
        if(matrix[i][j] == 1){
            matrix[i][j] = 1 + fmin(matrix[i-1][j-1], fmin(matrix[i-1][j], matrix[i][j-1]));
        }
        count += matrix[i][j];
    }
}

return count;
}