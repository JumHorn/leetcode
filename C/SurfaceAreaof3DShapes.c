

int surfaceArea(int** grid, int gridSize, int* gridColSize){
	int res=0;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<gridSize;j++)
			if(grid[i][j]>0)
				res++;
	res*=2;
	for(int i=0;i<gridSize;i++)
		for(int j=0;j<gridSize;j++)
		{
			if(i>0)
			{
				if(grid[i][j]>grid[i-1][j])
					res+=grid[i][j]-grid[i-1][j];
			}
			else
				res+=grid[i][j];

			if(i<gridSize-1)
			{
				if(grid[i][j]>grid[i+1][j])
					res+=grid[i][j]-grid[i+1][j];
			}
			else
				res+=grid[i][j];

			if(j>0)
			{
				if(grid[i][j]>grid[i][j-1])
					res+=grid[i][j]-grid[i][j-1];
			}
			else
				res+=grid[i][j];

			if(j<gridSize-1)
			{
				if(grid[i][j]>grid[i][j+1])
					res+=grid[i][j]-grid[i][j+1];
			}
			else
				res+=grid[i][j];
		}

	return res;
}



