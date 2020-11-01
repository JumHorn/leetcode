#include <vector>
using namespace std;

class Solution
{
public:
	int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
	{
		int res = 0, N = startTime.size();
		for (int i = 0; i < N; ++i)
		{
			if (queryTime >= startTime[i] && queryTime <= endTime[i])
				++res;
		}
		return res;
	}
};