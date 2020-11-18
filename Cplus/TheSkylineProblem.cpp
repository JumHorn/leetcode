#include <set>
#include <vector>
using namespace std;

/*
range check
*/

class Solution
{
public:
	vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
	{
		vector<vector<int>> res;
		int maxheight = 0;
		multiset<pair<int, int>> criticalpoint; //{range bounder,height}
		for (auto &b : buildings)
		{
			criticalpoint.insert({b[0], -b[2]});
			criticalpoint.insert({b[1], b[2]});
		}
		multiset<int> height({0});
		for (auto p : criticalpoint)
		{
			if (p.second < 0)
				height.insert(-p.second);
			else
				height.erase(height.find(p.second));

			if (*height.rbegin() != maxheight)
			{
				maxheight = *height.rbegin();
				res.push_back({p.first, maxheight});
			}
		}
		return res;
	}
};