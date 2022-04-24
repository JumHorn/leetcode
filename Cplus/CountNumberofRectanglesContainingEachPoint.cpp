#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
	{
		vector<vector<int>> count(101); //l value sorted
		for (auto &r : rectangles)
			count[r[1]].push_back(r[0]);
		for (auto &v : count)
			sort(v.begin(), v.end());
		vector<int> res;
		for (auto &point : points)
		{
			int x = point[0], y = point[1];
			res.emplace_back(0);
			for (int i = y; i < 101; ++i)
			{
				auto it = lower_bound(count[i].begin(), count[i].end(), x);
				res.back() += count[i].size() - (it - count[i].begin());
			}
		}
		return res;
	}
};