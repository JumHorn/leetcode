#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumMoney(vector<vector<int>> &transactions)
	{
		long long totalLose = 0, maxval = 0;
		for (auto &trans : transactions)
		{
			maxval = max(maxval, (long long)min(trans[0], trans[1]));
			totalLose += max(0, trans[0] - trans[1]);
		}
		return totalLose + maxval;
	}
};