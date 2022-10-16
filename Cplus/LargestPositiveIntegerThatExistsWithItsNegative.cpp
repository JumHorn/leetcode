#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMaxK(vector<int> &nums)
	{
		vector<int> count(1001);
		sort(nums.begin(), nums.end());
		int res = -1;
		for (auto n : nums)
		{
			if (n <= 0)
				count[-n] = 1;
			else if (count[n] == 1)
				res = n;
		}
		return res;
	}
};