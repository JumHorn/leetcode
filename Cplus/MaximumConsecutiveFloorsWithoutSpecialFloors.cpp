#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxConsecutive(int bottom, int top, vector<int> &special)
	{
		if (special.empty())
			return top - bottom + 1;
		sort(special.begin(), special.end());
		int pre = special[0], res = 0;
		res = max(top - special.back(), special.front() - bottom);
		for (auto n : special)
		{
			res = max(res, n - pre - 1);
			pre = n;
		}
		return res;
	}
};