#include <vector>
using namespace std;

class Solution
{
public:
	bool hasTrailingZeros(vector<int> &nums)
	{
		int count = 0;
		for (auto n : nums)
		{
			if ((n & 1) == 0)
			{
				if (++count == 2)
					return true;
			}
		}
		return false;
	}
};