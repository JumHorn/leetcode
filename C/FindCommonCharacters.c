#include<string.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void getMap(char* arr,int* other)
{
	for(int i=0;i<(int)strlen(arr);i++)
		++other[arr[i]-'a'];
}

char ** commonChars(char ** A, int ASize, int* returnSize){
	*returnSize=0;
	if(ASize<1)
		return NULL;
	int res[26]={0},other[26]={0};
	getMap(A[0],res);
	for(int i=1;i<ASize;i++)
	{
		memset(other,0,sizeof(other));
		getMap(A[i],other);
		for(int j=0;j<26;j++)
			res[j]=res[j]>other[j]?other[j]:res[j];
	}
	int count=0;
	for(int i=0;i<26;i++)
		count+=res[i];
	*returnSize=count;
	if(count==0)
		return NULL;
	char **p=(char**)malloc(sizeof(char*)*count);
	for(int i=0;i<count;i++)
	{
		p[i]=(char*)malloc(sizeof(char)*2);
		p[i][1]='\0';
	}
	count=0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<res[i];j++)
			p[count++][0]='a'+i;
	}
	return p;
}

