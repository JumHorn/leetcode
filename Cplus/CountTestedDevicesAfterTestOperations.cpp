#include <vector>
using namespace std;

class Solution
{
public:
	int countTestedDevices(vector<int> &batteryPercentages)
	{
		int N = batteryPercentages.size(), res = 0, d = 0;
		for (int i = 0; i < N; ++i)
		{
			if (batteryPercentages[i] - d > 0)
			{
				++d;
				++res;
			}
		}
		return res;
	}
};