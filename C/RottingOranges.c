

int rotting(int** grid,int gridSize,int colSize)
{
	int res=0;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<colSize;j++)
		{
			if(grid[i][j]==2)
			{
				if(i>0&&grid[i-1][j]==1)
				{
					res++;
					grid[i-1][j]=3;
				}
				if(i<gridSize-1&&grid[i+1][j]==1)
				{
					res++;
					grid[i+1][j]=3;
				}
				if(j>0&&grid[i][j-1]==1)
				{
					res++;
					grid[i][j-1]=3;
				}
				if(j<colSize-1&&grid[i][j+1]==1)
				{
					res++;
					grid[i][j+1]=3;
				}
			}
		}
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<colSize;j++)
			if(grid[i][j]==3)
				grid[i][j]=2;
	return res;
}

int checkGrid(int** grid,int gridSize,int colSize)
{
	int res=0;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<colSize;j++)
			if(grid[i][j]==1)
				res++;
	return res;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize){
	int step=0;
	while(rotting(grid,gridSize,gridColSize[0])>0)
		step++;
	if(checkGrid(grid,gridSize,gridColSize[0])>0)
		return -1;
	return step;
}

