

int rotting(int** grid,int gridSize,int colSize,int rotnum)
{
	int res=0;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<colSize;j++)
		{
			if(grid[i][j]==rotnum)
			{
				if(i>0&&grid[i-1][j]==1)
				{
					res++;
					grid[i-1][j]=rotnum+1;
				}
				if(i<gridSize-1&&grid[i+1][j]==1)
				{
					res++;
					grid[i+1][j]=rotnum+1;
				}
				if(j>0&&grid[i][j-1]==1)
				{
					res++;
					grid[i][j-1]=rotnum+1;
				}
				if(j<colSize-1&&grid[i][j+1]==1)
				{
					res++;
					grid[i][j+1]=rotnum+1;
				}
			}
		}
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
	int step=0,rotnum=2;
	while(rotting(grid,gridSize,gridColSize[0],rotnum++)>0)
		step++;
	if(checkGrid(grid,gridSize,gridColSize[0])>0)
		return -1;
	return step;
}

