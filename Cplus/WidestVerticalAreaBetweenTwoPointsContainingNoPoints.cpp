#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxWidthOfVerticalArea(vector<vector<int>> &points)
	{
		set<int> s;
		for (auto &p : points)
			s.insert(p[0]);
		auto iter = s.begin();
		++iter;
		int res = 0;
		for (auto it = s.begin(); iter != s.end(); ++iter, ++it)
			res = max(res, *iter - *it);
		return res;
	}
};