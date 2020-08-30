#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumMoves(vector<vector<int>> &grid)
	{
		int n = grid.size();
		queue<pair<int, int>> q;
		set<pair<int, int>> s;
		q.push({0, 1});
		s.insert({0, 1});
		int res = -1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				auto at = q.front();
				q.pop();
				if (at.first == n * (n - 1) + n - 2 && at.second == n * (n - 1) + n - 1)
					return res;
				int tailrow = at.first / n, tailcol = at.first % n, headrow = at.second / n, headcol = at.second % n;
				if (tailrow == headrow)
				{
					//right
					if (headcol + 1 < n && grid[headrow][headcol + 1] == 0)
					{
						pair<int, int> p = {at.second, at.second + 1};
						if (s.find(p) == s.end())
						{
							s.insert(p);
							q.push(p);
						}
					}
					//down
					if (headrow + 1 < n && grid[headrow + 1][headcol] == 0 && grid[tailrow + 1][tailcol] == 0)
					{
						pair<int, int> p = {at.first + n, at.second + n};
						if (s.find(p) == s.end())
						{
							s.insert(p);
							q.push(p);
						}

						//clockwise
						p = {at.first, at.first + n};
						if (s.find(p) == s.end())
						{
							s.insert(p);
							q.push(p);
						}
					}
				}
				else
				{
					//down
					if (headrow + 1 < n && grid[headrow + 1][headcol] == 0)
					{
						pair<int, int> p = {at.second, at.second + n};
						if (s.find(p) == s.end())
						{
							s.insert(p);
							q.push(p);
						}
					}
					//right
					if (headcol + 1 < n && grid[headrow][headcol + 1] == 0 && grid[tailrow][tailcol + 1] == 0)
					{
						pair<int, int> p = {at.first + 1, at.second + 1};
						if (s.find(p) == s.end())
						{
							s.insert(p);
							q.push(p);
						}

						//counter-clockwise
						p = {at.first, at.first + 1};
						if (s.find(p) == s.end())
						{
							s.insert(p);
							q.push(p);
						}
					}
				}
			}
		}
		return -1;
	}
};