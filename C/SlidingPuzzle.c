
#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

typedef struct pair
{
	int first;
	int second;
} pair;

int compress(int **board, int M, int N)
{
	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			res = res * 10 + board[i][j];
	}
	return res;
}

void decompress(int **board, int M, int N, int state)
{
	for (int i = M - 1; i >= 0; --i)
	{
		for (int j = N - 1; j >= 0; --j)
		{
			board[i][j] = state % 10;
			state /= 10;
		}
	}
}

pair findZero(int **board, int M, int N)
{
	pair zero;
	zero.first = zero.second = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 0)
			{
				zero.first = i;
				zero.second = j;
				return zero;
			}
		}
	}
	return zero;
}

int slidingPuzzle(int **board, int boardSize, int *boardColSize)
{
	int M = boardSize, N = *boardColSize;
	int seen[543211] = {0}, res = 0;
	int size = 50000, queue[size], front = 0, rear = 0; //queue definition
	int state = compress(board, M, N), finalstate = 123450;
	if (state == finalstate)
		return res;
	queue[rear] = state;
	rear = (rear - 1 + size) % size; //push back
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //qsize
		while (--s >= 0)
		{
			state = queue[front];
			front = (front - 1 + size) % size; //pop front
			decompress(board, M, N, state);
			pair zero = findZero(board, M, N);
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			for (int k = 0; k < 4; ++k)
			{
				int x = zero.first + path[k], y = zero.second + path[k + 1];
				if (x < 0 || x >= M || y < 0 || y >= N)
					continue;
				swap(board[zero.first][zero.second], board[x][y]);
				state = compress(board, M, N);
				if (seen[state] == 0)
				{
					if (state == finalstate)
						return res;
					seen[state] = 1;
					queue[rear] = state;
					rear = (rear - 1 + size) % size; //push back
				}
				swap(board[zero.first][zero.second], board[x][y]);
			}
		}
	}
	return -1;
}