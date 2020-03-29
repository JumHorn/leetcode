#include <vector>
using namespace std;

class Solution
{
public:
	int findLucky(vector<int>& arr)
	{
		vector<int> dp(501);
		for (auto n : arr)
			++dp[n];
		for (int i = dp.size() - 1; i > 0; i--)
			if (dp[i] == i)
				return i;
		return -1;
	}
};
