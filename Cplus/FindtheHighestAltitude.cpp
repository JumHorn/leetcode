#include <vector>
using namespace std;

class Solution
{
public:
	int largestAltitude(vector<int> &gain)
	{
		int res = 0, start = 0;
		for (auto n : gain)
		{
			start += n;
			res = max(res, start);
		}
		return res;
	}
};