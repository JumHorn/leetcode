#include <vector>
using namespace std;

class Solution
{
public:
	int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
	{
		int minute = targetSeconds / 60, second = targetSeconds % 60, res = INT_MAX;
		vector<int> v = createNum(minute, second);
		if (minute <= 99)
			res = costSetTime(startAt, moveCost, pushCost, v);
		if (minute > 0)
		{
			--minute;
			second += 60;
			if (second <= 99)
			{
				v = createNum(minute, second);
				res = min(res, costSetTime(startAt, moveCost, pushCost, v));
			}
		}

		return res;
	}

	vector<int> createNum(int minute, int second)
	{
		vector<int> v;
		if (minute < 10)
		{
			if (minute > 0)
				v.push_back(minute);
		}
		else
		{
			v.push_back(minute / 10);
			v.push_back(minute % 10);
		}
		if (second < 10)
		{
			if (minute > 0)
				v.push_back(0);
			v.push_back(second);
		}
		else
		{
			v.push_back(second / 10);
			v.push_back(second % 10);
		}
		return v;
	}

	int costSetTime(int startAt, int moveCost, int pushCost, vector<int> &nums)
	{
		int res = 0;
		for (auto n : nums)
		{
			if (n != startAt)
				res += moveCost;
			res += pushCost;
			startAt = n;
		}
		return res;
	}
};