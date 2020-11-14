#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Range
{
public:
	Range()
	{
	}

	int addRange(int left, int right, int height)
	{
		auto iter = range.lower_bound({left, right});
		auto prev = iter;
		int res = 0;
		if (prev != range.begin())
		{
			--prev;
			if (prev->first.second > left)
			{
				res = max(res, prev->second);
				range.insert({{prev->first.first, left}, prev->second});
				if (prev->first.second > right)
					range.insert({{right, prev->first.second}, prev->second});
				range.erase(prev);
			}
		}
		while (iter != range.end() && iter->first.second <= right)
		{
			res = max(res, iter->second);
			iter = range.erase(iter);
		}
		if (iter != range.end() && iter->first.first < right)
		{
			res = max(res, iter->second);
			range.insert({{right, iter->first.second}, iter->second});
			range.erase(iter);
		}
		res += height;
		range.insert({{left, right}, res});
		return res;
	}

private:
	map<pair<int, int>, int> range; //{{interval},height}
};

class Solution
{
public:
	vector<int> fallingSquares(vector<vector<int>> &positions)
	{
		Range range;
		vector<int> res;
		int maxheight = 0;
		for (auto &pos : positions)
		{
			maxheight = max(maxheight, range.addRange(pos[0], pos[0] + pos[1], pos[1]));
			res.push_back(maxheight);
		}
		return res;
	}
};