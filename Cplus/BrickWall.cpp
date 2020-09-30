#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int leastBricks(vector<vector<int>> &wall)
	{
		unordered_map<int, int> m; //{edge,edge count}
		int res = wall.size(), N = wall.size();
		for (auto &row : wall)
		{
			int prefixsum = 0;
			for (int i = 0; i < (int)row.size() - 1; ++i) // skip last brick
			{
				prefixsum += row[i];
				res = min(res, N - (++m[prefixsum]));
			}
		}
		return res;
	}
};