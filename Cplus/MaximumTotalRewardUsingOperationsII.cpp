#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

// remove duplicate to accelerate

class Solution
{
public:
	int maxTotalReward(vector<int> &rewardValues)
	{
		sort(rewardValues.begin(), rewardValues.end());
		bitset<100000> dp(1);
		for (auto n : rewardValues)
		{
			int shift = dp.size() - n;
			dp |= dp << shift >> shift << n;
		}
		for (int i = rewardValues.back() * 2 - 1; i >= 0; --i)
		{
			if (dp.test(i))
				return i;
		}
		return -1;
	}
};