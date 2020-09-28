#include <vector>
using namespace std;

class Solution
{
public:
	int findPoisonedDuration(vector<int> &timeSeries, int duration)
	{
		int res = 0, poison_lasted = -1;
		for (auto t : timeSeries)
		{
			if (t <= poison_lasted)
				res += t + duration - poison_lasted;
			else
				res += duration;
			poison_lasted = t + duration;
		}
		return res;
	}
};