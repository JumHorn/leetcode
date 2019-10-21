#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
	int *h=(int*)calloc(gridSize,sizeof(int));
	int *v=(int*)calloc(*gridColSize,sizeof(int));
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<*gridColSize;j++)
			h[i]=max(grid[i][j],h[i]);
	for(int j=0;j<*gridColSize;j++)
		for(int i=0;i<gridSize;i++)
			v[j]=max(grid[i][j],v[j]);
	int res=0;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<*gridColSize;j++)
			res+=min(h[i],v[j])-grid[i][j];
	return res;
}


