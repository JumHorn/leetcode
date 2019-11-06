#include<stdlib.h>

int arrayEquals(int* arr1,int* arr2,int size)
{
	for(int i=0;i<size;i++)
		if(arr1[i]!=arr2[i])
			return 0;
	return 1;
}

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
	int* p=(int*)malloc(*matrixColSize*sizeof(int));
	int* visited=(int*)calloc(matrixSize,sizeof(int));
	int res=0;
	for(int i=0;i<matrixSize;i++)
	{
		if(visited[i]!=0)
			continue;
		for(int j=0;j<*matrixColSize;j++)
			p[j]=1-matrix[i][j];
		int count=0;
		for(int j=0;j<matrixSize;j++)
		{
			if(i==j)
			{
				count++;
				visited[i]=1;
			}
			if(visited[i]!=0)
				continue;
			if(arrayEquals(matrix[i],matrix[j],*matrixColSize)>0||arrayEquals(matrix[j],p,*matrixColSize)>0)
				count++;
		}
		if(count>res)
			res=count;
	}
	return res;
}
