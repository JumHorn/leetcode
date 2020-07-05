#include <vector>
using namespace std;

class Solution
{
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right)
	{
		int res = 0, l = 0, r = 0;
		if (!left.empty())
		{
			l = *max_element(left.begin(), left.end());
			res = max(res, l);
		}
		if (!right.empty())
		{
			r = *min_element(right.begin(), right.end());
			res = max(res, n - r);
		}
		return res;
	}
};
