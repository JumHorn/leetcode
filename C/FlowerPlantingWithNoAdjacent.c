#include<stdlib.h>
#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int flower(int n)
{
	int res=0;
	while((1<<res)&n)
		res++;
	return res+1;
}

void dfs(int **graph,int *res,int index,int* len)
{
	int color=0;
	for(int i=0;i<len[index];i++)
		if(res[graph[index][i]]!=0)
			color|=1<<(res[i]-1);
	res[index]=flower(color);
}

int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize){
	*returnSize=N;
	int* res=(int*)calloc(N,sizeof(int));
	int* len=(int*)calloc(N,sizeof(int));
	int** graph=(int**)malloc(N*sizeof(int*));
	for(int i=0;i<N;i++)
		graph[i]=(int*)calloc(100,sizeof(int));
	for(int i=0;i<pathsSize;i++)
	{
		graph[paths[i][0]-1][len[paths[i][0]-1]++]=paths[i][1]-1;
		graph[paths[i][1]-1][len[paths[i][1]-1]++]=paths[i][0]-1;
	}
	for(int i=0;i<N;i++)
	{
		if(res[i]==0)
			dfs(graph,res,i,len);
	}
	return res;
}

