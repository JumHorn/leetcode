#include<stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
	*returnSize=AColSize[0];
	*returnColumnSizes=(int*)malloc(sizeof(int)*AColSize[0]);
	for(int i=0;i<AColSize[0];i++)
		(*returnColumnSizes)[i]=ASize;
	int **res=(int **)malloc(sizeof(int*)*AColSize[0]);
	for(int i=0;i<AColSize[0];i++)
		res[i]=(int*)malloc(sizeof(int)*ASize);
	for(int i=0;i<ASize;i++)
		for(int j=0;j<AColSize[0];j++)
			res[j][i]=A[i][j];
	return res;
}

