#include<stdlib.h>


int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
	int* p=(int*)malloc(matrixSize*sizeof(int));
	for(int i=0;i<matrixSize;i++)
		p[i]=matrix[i][0];
	int res=0;
	for(int j=1;j<*matrixColSize;j++)
	{
		int count=0,reverse=0;
		for(int i=0;i<matrixSize;i++)
		{
			if(matrix[i][j]==p[i])
				count++;
			if(1-matrix[i][j]==p[i])
				reverse++;
		}
		if(reverse>count)
			for(int i=0;i<matrixSize;i++)
				matrix[i][j]=1-matrix[i][j];
		for(int i=0;i<matrixSize;i++)
			if(matrix[i][j]!=p[i])
				p[i]=-1;
	}
	for(int i=0;i<matrixSize;i++)
		if(p[i]>=0)
			res++;
	return res;
}