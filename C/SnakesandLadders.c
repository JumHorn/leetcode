
void getIndex(int index, int N, int *row, int *col)
{
	*row = (index - 1) / N;
	*col = (index - 1) % N;
	if (*row % 2 == 1)
		*col = N - 1 - *col;
	*row = N - 1 - *row;
}

int snakesAndLadders(int **board, int boardSize, int *boardColSize)
{
	int res = 0, N = boardSize, target = N * N;
	int qsize = N * N, queue[qsize], front = 0, rear = 0;

	queue[rear] = 1;
	rear = (rear - 1 + qsize) % qsize; //push back

	board[N - 1][0] = -2; //-2 already visited,-1 can not cross
	while (front != rear) //queue not empty
	{
		int size = (front - rear + qsize) % qsize; //size
		++res;
		while (--size >= 0)
		{
			int pos = queue[front];
			front = (front - 1 + qsize) % qsize; //pop front

			for (int k = 1; k <= 6; ++k)
			{
				int index = pos + k;
				if (index > target)
					break;
				int i, j;
				getIndex(index, N, &i, &j);
				if (board[i][j] == -2)
					continue;
				if (board[i][j] != -1)
					index = board[i][j];
				board[i][j] = -2;
				if (index == target)
					return res;

				queue[rear] = index;
				rear = (rear - 1 + qsize) % qsize; //push back
			}
		}
	}
	return -1;
}