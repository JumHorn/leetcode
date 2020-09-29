#include <algorithm>
#include <climits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMinDifference(vector<string> &timePoints)
	{
		int res = INT_MAX;
		sort(timePoints.begin(), timePoints.end());
		for (int i = 1; i < (int)timePoints.size(); ++i)
			res = min(res, timeDiff(timePoints[i - 1], timePoints[i]));
		res = min(res, 1440 + timeDiff(timePoints.back(), timePoints.front()));
		return res;
	}

	int timeDiff(string &t0, string &t1)
	{
		return timeToZero(t1) - timeToZero(t0);
	}

	int timeToZero(string &time)
	{
		stringstream ss(time);
		int hour, minute;
		char c;
		ss >> hour >> c >> minute;
		return hour * 60 + minute;
	}
};