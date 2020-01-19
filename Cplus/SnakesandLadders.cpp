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
		board[N - 1][0] = -2;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int tmp = q.front();
				q.pop();
				for (int k = 1; k <= 6; k++)
				{
					int index = tmp + k;
					if (index > target)
						break;
					int i, j;
					getIndex(index, N, i, j);
					if (board[i][j] == -2)
						continue;
					if (board[i][j] != -1)
					{
						if (board[i][j] == target)
							return res;
						int m = board[i][j];
						board[i][j] = -2;
						q.push(m);
					}
					else
					{
						if (index == target)
							return res;
						q.push(index);
						board[i][j] = -2;
					}
				}
			}
		}
		return -1;
	}

	void getIndex(int index, int N, int &i, int &j)
	{
		i = (index - 1) / N;
		j = (index - 1) % N;
		if (i % 2 == 1)
			j = N - 1 - j;
		i = N - 1 - i;
	}
};