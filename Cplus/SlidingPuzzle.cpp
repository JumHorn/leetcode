#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int slidingPuzzle(vector<vector<int>> &board)
	{
		unordered_set<int> seen;
		queue<int> q;
		int res = 0, M = board.size(), N = board[0].size();
		int state = compress(board), finalstate = 123450;
		if (state == finalstate)
			return res;
		q.push(state);
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				state = q.front();
				q.pop();
				decompress(board, state);
				pair<int, int> zero = findZero(board);
				//board dfs direction
				int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
				for (int k = 0; k < 4; k++)
				{
					int x = zero.first + path[k][0], y = zero.second + path[k][1];
					if (x < 0 || x >= M || y < 0 || y >= N)
						continue;
					swap(board[zero.first][zero.second], board[x][y]);
					state = compress(board);
					if (seen.find(state) == seen.end())
					{
						if (state == finalstate)
							return res;
						seen.insert(state);
						q.push(state);
					}
					swap(board[zero.first][zero.second], board[x][y]);
				}
			}
		}
		return -1;
	}

	int compress(vector<vector<int>> &board)
	{
		int M = board.size(), N = board[0].size();
		int res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; j++)
				res = res * 10 + board[i][j];
		}
		return res;
	}

	void decompress(vector<vector<int>> &board, int state)
	{
		int M = board.size(), N = board[0].size();
		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				board[i][j] = state % 10;
				state /= 10;
			}
		}
	}

	pair<int, int> findZero(vector<vector<int>> &board)
	{
		int M = board.size(), N = board[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 0)
					return {i, j};
			}
		}
		return {0, 0};
	}
};