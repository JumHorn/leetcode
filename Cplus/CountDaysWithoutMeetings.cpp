#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int countDays(int days, vector<vector<int>> &meetings)
	{
		sort(meetings.begin(), meetings.end());
		int res = 0, d = 0;
		for (auto &v : meetings)
		{
			if (v[0] > d && days > d)
				res += min(days, v[0]) - d - 1;
			d = max(d, v[1]);
		}
		return res + max(0, days - d);
	}
};