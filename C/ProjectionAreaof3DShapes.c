

int projectionArea(int** grid, int gridSize, int* gridColSize){
	int top=0,left=0,right=0;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<gridColSize[i];j++)
			if(grid[i][j]>0)
				top+=1;
	for(int i=0;i<gridSize;i++)
	{
		int max=0;
		for(int j=0;j<gridColSize[i];j++)
			if(grid[i][j]>max)
				max=grid[i][j];
		left+=max;
	}
	int maxcol=0;
	for(int i=0;i<gridSize;i++)
		if(gridColSize[i]>maxcol)
			maxcol=gridColSize[i];
	for(int j=0;j<maxcol;j++)
	{
		int max=0;
		for(int i=0;i<gridSize;i++)
			if(gridColSize[i]>j&&grid[i][j]>max)
				max=grid[i][j];
		right+=max;
	}
	return top+left+right;
}



