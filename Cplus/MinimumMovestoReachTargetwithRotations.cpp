#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumMoves(vector<vector<int>> &grid)
	{
		int N = grid.size();
		queue<pair<int, int>> q;
		set<pair<int, int>> seen;
		q.push({0, 1});
		seen.insert({0, 1});
		int res = -1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				auto at = q.front();
				q.pop();
				if (at.first == N * (N - 1) + N - 2 && at.second == N * (N - 1) + N - 1)
					return res;
				int tailrow = at.first / N, tailcol = at.first % N, headrow = at.second / N, headcol = at.second % N;
				if (tailrow == headrow)
				{
					//right
					if (headcol + 1 < N && grid[headrow][headcol + 1] == 0)
						tryMoveToPos({at.second, at.second + 1}, seen, q);
					//down
					if (headrow + 1 < N && grid[headrow + 1][headcol] == 0 && grid[tailrow + 1][tailcol] == 0)
					{
						tryMoveToPos({at.first + N, at.second + N}, seen, q);
						//clockwise
						tryMoveToPos({at.first, at.first + N}, seen, q);
					}
				}
				else
				{
					//down
					if (headrow + 1 < N && grid[headrow + 1][headcol] == 0)
						tryMoveToPos({at.second, at.second + N}, seen, q);
					//right
					if (headcol + 1 < N && grid[headrow][headcol + 1] == 0 && grid[tailrow][tailcol + 1] == 0)
					{
						tryMoveToPos({at.first + 1, at.second + 1}, seen, q);
						//counter-clockwise
						tryMoveToPos({at.first, at.first + 1}, seen, q);
					}
				}
			}
		}
		return -1;
	}

	void tryMoveToPos(const pair<int, int> &pos, set<pair<int, int>> &seen, queue<pair<int, int>> &q)
	{
		if (seen.find(pos) == seen.end())
		{
			seen.insert(pos);
			q.push(pos);
		}
	}
};