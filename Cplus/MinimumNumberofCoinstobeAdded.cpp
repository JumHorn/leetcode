#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumAddedCoins(vector<int> &coins, int target)
	{
		sort(coins.begin(), coins.end());
		int res = 0, val = 1, t = 0;
		for (auto n : coins)
		{
			while (n > val && t < target)
			{
				++res;
				t += val;
				val = t + 1;
			}
			if (t >= target)
				break;
			t += n;
			val = max(val, t + 1);
		}
		while (t < target)
		{
			++res;
			t += val;
			val = t + 1;
		}
		return res;
	}
};