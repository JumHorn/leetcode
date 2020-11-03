#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
	{
		set<pair<int, int>> block;
		for (int i = 0; i < (int)blocked.size(); ++i)
			block.insert({blocked[i][0], blocked[i][1]});
		return bfs(block, source, target) && bfs(block, target, source);
	}

	bool bfs(set<pair<int, int>> &block, vector<int> &source, vector<int> &target)
	{
		queue<pair<int, int>> q;
		set<pair<int, int>> seen;
		q.push({source[0], source[1]});
		seen.insert({source[0], source[1]});
		int path[5] = {-1, 0, 1, 0, -1}, count = 1;
		while (count < (int)block.size() && !q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (target[0] == dx && target[1] == dy)
						return true;
					if (dx < 0 || dx >= 1e6 || dy < 0 || dy >= 1e6)
						continue;
					if (block.find({dx, dy}) == block.end() && seen.find({dx, dy}) == seen.end())
					{
						q.push({dx, dy});
						seen.insert({dx, dy});
					}
				}
			}
			++count;
		}
		return !q.empty();
	}
};