#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxScore(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), greater<int>());
		long long sum = 0, res = 0;
		for (auto n : nums)
		{
			sum += n;
			if (sum <= 0)
				break;
			++res;
		}
		return res;
	}
};