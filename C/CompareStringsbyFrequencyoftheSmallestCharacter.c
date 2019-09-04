#include<string.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getSmallestFrequency(char* arr)
{
	int len=strlen(arr),freq=0;
	char smallest='z';
	for(int i=0;i<len;i++)
	{
		if(arr[i]<smallest)
		{
			smallest=arr[i];
			freq=1;
		}
		else if(arr[i]==smallest)
			++freq;
	}
	return freq;
}

int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
	*returnSize=queriesSize;
	int* queriesarr=(int*)malloc(queriesSize*sizeof(int));
	int* wordsarr=(int*)malloc(wordsSize*sizeof(int));
	for(int i=0;i<queriesSize;i++)
		queriesarr[i]=getSmallestFrequency(queries[i]);
	for(int i=0;i<wordsSize;i++)
		wordsarr[i]=getSmallestFrequency(words[i]);
	for(int i=0;i<queriesSize;i++)
	{
		int num=0;
		for(int j=0;j<wordsSize;j++)
		{
			if(queriesarr[i]<wordsarr[j])
				num++;
		}
		queriesarr[i]=num;
	}
	return queriesarr;
}

