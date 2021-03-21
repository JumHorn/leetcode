#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMaximumConsecutive(vector<int> &coins)
	{
		sort(coins.begin(), coins.end());
		int maxamount = 0;
		for (auto n : coins)
		{
			if (n - 1 > maxamount)
				return maxamount + 1;
			maxamount += n;
		}
		return maxamount + 1;
	}
};