#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxTotalReward(vector<int> &rewardValues)
	{
		sort(rewardValues.begin(), rewardValues.end());
		int N = rewardValues.size(), maxval = rewardValues.back();
		vector<int> seen(2001);
		seen[0] = 1;
		seen[rewardValues[0]] = 1;
		for (int i = 1; i < N - 1; ++i)
		{
			for (int j = rewardValues[i] - 1; j >= 0; --j)
			{
				if (seen[j] == 1 && rewardValues[i] + j < maxval)
					seen[rewardValues[i] + j] = 1;
			}
		}
		for (int i = rewardValues[N - 1] - 1; i >= 0; --i)
		{
			if (seen[i] != 0)
				return i + rewardValues[N - 1];
		}
		return -1;
	}
};