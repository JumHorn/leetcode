#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int snakesAndLadders(vector<vector<int>> &board)
	{
		queue<int> q;
		int res = 0, N = board.size(), target = N * N;
		q.push(1);
		board[N - 1][0] = -2; //-2 already visited,-1 can not cross
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int pos = q.front();
				q.pop();
				for (int k = 1; k <= 6; ++k)
				{
					int index = pos + k;
					if (index > target)
						break;
					int i, j;
					getIndex(index, N, i, j);
					if (board[i][j] == -2)
						continue;
					if (board[i][j] != -1)
						index = board[i][j];
					board[i][j] = -2;
					if (index == target)
						return res;
					q.push(index);
				}
			}
		}
		return -1;
	}

	void getIndex(int index, int N, int &row, int &col)
	{
		row = (index - 1) / N;
		col = (index - 1) % N;
		if (row % 2 == 1)
			col = N - 1 - col;
		row = N - 1 - row;
	}
};