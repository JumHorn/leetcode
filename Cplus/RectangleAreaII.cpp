#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int rectangleArea(vector<vector<int>> &rectangles)
	{
		map<int, vector<vector<int>>> m; //{x,{{ylower,yupper,in/out}}}
		for (auto &rect : rectangles)
		{
			m[rect[0]].push_back({rect[1], rect[3], 1});
			m[rect[2]].push_back({rect[1], rect[3], -1});
		}
		multiset<int> lower, upper;
		unsigned long long pre = 0, res = 0;
		for (auto &n : m)
		{
			int y = 0;
			if (!lower.empty())
				y = *upper.rbegin() - *lower.begin();
			res += y * (n.first - pre);
			pre = n.first;

			//add or delete
			for (auto &yaxis : n.second)
			{
				if (yaxis[2] == 1)
				{
					lower.insert(yaxis[0]);
					upper.insert(yaxis[1]);
				}
				else
				{
					lower.erase(lower.find(yaxis[0]));
					upper.erase(upper.find(yaxis[1]));
				}
			}
		}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};