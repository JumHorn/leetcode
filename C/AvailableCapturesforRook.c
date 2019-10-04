


int numRookCaptures(char** board, int boardSize, int* boardColSize){
	int x,y;
	for(int i=0;i<boardSize;i++)
		for(int j=0;j<boardColSize[0];j++)
			if(board[i][j]=='R')
			{
				x=i;
				y=j;
				i=boardSize;
				break;
			}
	int res=0,d=x;
	while(--d>=0)
	{
		if(board[d][y]=='B')
			break;
		if(board[d][y]=='p')
		{
			res++;
			break;
		}
	}
	d=x;
	while(++d<boardSize)
	{
		if(board[d][y]=='B')
			break;
		if(board[d][y]=='p')
		{
			res++;
			break;
		}
	}
	d=y;
	while(--d>=0)
	{
		if(board[x][d]=='B')
			break;
		if(board[x][d]=='p')
		{
			res++;
			break;
		}
	}
	d=y;
	while(++d<boardColSize[0])
	{
		if(board[x][d]=='B')
			break;
		if(board[x][d]=='p')
		{
			res++;
			break;
		}
	}

	return res;
}

