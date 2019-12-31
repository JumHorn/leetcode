#include <queue>
#include <vector>
using namespace std;

class Solution
{
	struct info
	{
		int i;
		int j;
		int k;
		int step;
		info(int _i = 0, int _j = 0, int _k = 0, int _step = 0) : i(_i), j(_j), k(_k), step(_step)
		{
		}
	};

public:
	int shortestPath(vector<vector<int>> &grid, int k)
	{
		int m = grid.size(), n = grid[0].size();
		if (k >= m + n - 1)
			return m + n - 2;
		vector<vector<vector<int>>> goal(m, vector<vector<int>>(n, vector<int>((k+1), 5000)));
		queue<info> q;
		q.push(info(0, 0, k, 0));
		int res = 0;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				info top = q.front();
				q.pop();
				info tmp = top;
				if (tmp.i - 1 >= 0)
				{
					tmp.i -= 1;
					tmp.k -= grid[tmp.i][tmp.j];
					tmp.step += 1;
					if (tmp.k >= 0 && tmp.step < goal[tmp.i][tmp.j][tmp.k])
					{
						goal[tmp.i][tmp.j][tmp.k] = tmp.step;
						if (tmp.i == m - 1 && tmp.j == n - 1)
							return res;
						q.push(tmp);
					}
				}

				tmp = top;
				if (tmp.i + 1 < m)
				{
					tmp.i += 1;
					tmp.k -= grid[tmp.i][tmp.j];
					tmp.step += 1;
					if (tmp.k >= 0 && tmp.step < goal[tmp.i][tmp.j][tmp.k])
					{
						goal[tmp.i][tmp.j][tmp.k] = tmp.step;
						if (tmp.i == m - 1 && tmp.j == n - 1)
							return res;
						q.push(tmp);
					}
				}

				tmp = top;
				if (tmp.j - 1 >= 0)
				{
					tmp.j -= 1;
					tmp.k -= grid[tmp.i][tmp.j];
					tmp.step += 1;
					if (tmp.k >= 0 && tmp.step < goal[tmp.i][tmp.j][tmp.k])
					{
						goal[tmp.i][tmp.j][tmp.k] = tmp.step;
						if (tmp.i == m - 1 && tmp.j == n - 1)
							return res;
						q.push(tmp);
					}
				}

				tmp = top;
				if (tmp.j + 1 < n)
				{
					tmp.j += 1;
					tmp.k -= grid[tmp.i][tmp.j];
					tmp.step += 1;
					if (tmp.k >= 0 && tmp.step < goal[tmp.i][tmp.j][tmp.k])
					{
						goal[tmp.i][tmp.j][tmp.k] = tmp.step;
						if (tmp.i == m - 1 && tmp.j == n - 1)
							return res;
						q.push(tmp);
					}
				}
			}
		}
		return -1;
	}
};


int main()
{
	vector<vector<int>> v={{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
	Solution sol;
	sol.shortestPath(v,1);
	return 0;
}