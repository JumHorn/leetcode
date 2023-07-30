#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
	{
		int res = 0;
		for (auto n : hours)
		{
			if (n >= target)
				++res;
		}
		return res;
	}
};