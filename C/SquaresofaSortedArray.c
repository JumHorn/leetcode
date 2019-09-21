#include<stdlib.h>
#define swap(a,b) if((a)!=(b))(a)^=(b)^=(a)^=(b)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findMid(int* A,int ASize)
{
	int lo=0,hi=ASize-1,mi;
	while(lo<hi)
	{
		mi=(hi-lo)/2+lo;
		if(A[mi]<0)
			lo=mi+1;
		else
			hi=mi;
	}
	return lo;
}

int* squareArray(int* A,int ASize)
{
	for(int i=0;i<ASize;i++)
		A[i]*=A[i];
	return A;
}

int* sortedSquares(int* A, int ASize, int* returnSize){
	*returnSize=ASize;
	if(A[0]>=0)
		return squareArray(A,ASize);
	if(A[ASize-1]<=0)
	{
		int i=-1,j=ASize;
		while(++i<--j)
			swap(A[i],A[j]);
		return squareArray(A,ASize);
	}
	int *res=(int*)malloc(sizeof(int)*ASize);
	int positive=findMid(A,ASize);
	int negative=positive-1;
	int index=0;
	while(negative>=0&&positive<ASize)
		res[index++]=A[positive]-(-A[negative])<=0?A[positive++]:A[negative--];
	while(negative>=0)
		res[index++]=A[negative--];
	while(positive<ASize)
		res[index++]=A[positive++];
	return squareArray(res,ASize);
}
