#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getFloor(int n)
{
	long lo=0,hi=n,mi;
	while(lo<hi)
	{
		mi=(hi-lo)/2+lo;
		if(mi*(mi+1)<2*n)
			lo=mi+1;
		else
			hi=mi;
	}
	return lo-1;
}


int* distributeCandies(int candies, int num_people, int* returnSize){
	*returnSize=num_people;
	int *res=(int*)calloc(num_people,sizeof(int));
	int k=getFloor(candies);
	for(int i=0;i<num_people;i++)
		for(int j=i+1;j<=k;j+=num_people)
			res[i]+=j;
	res[k%num_people]+=candies-k*(k+1)/2;
	return res;
}