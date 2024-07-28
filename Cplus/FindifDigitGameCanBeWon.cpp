#include <vector>
using namespace std;

class Solution
{
public:
	bool canAliceWin(vector<int> &nums)
	{
		int sum = 0, s = 0, d = 0;
		for (auto n : nums)
		{
			if (n < 10)
				s += n;
			else
				d += n;
			sum += n;
		}
		return s > sum - s || d > sum - d;
	}
};