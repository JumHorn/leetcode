#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	bool increasingTriplet(vector<int> &nums)
	{
		int one = INT_MAX, two = INT_MAX;
		for (auto n : nums)
		{
			if (n > two)
				return true;
			if (n > one)
				two = n;
			else
				one = n;
		}
		return false;
	}
};