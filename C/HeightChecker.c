#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comp(const void* lhs,const void* rhs)
{
	return *(int*)lhs-*(int*)rhs;//if INT_MIN is present,this is error
}

int heightChecker(int* heights, int heightsSize){
	int *p=(int*)malloc(sizeof(int)*heightsSize);
	memcpy(p,heights,heightsSize*sizeof(int));
	qsort(p,heightsSize,sizeof(int),comp);
	int res=0;
	for(int i=0;i<heightsSize;i++)
		if(p[i]!=heights[i])
			res++;
	return res;
}

