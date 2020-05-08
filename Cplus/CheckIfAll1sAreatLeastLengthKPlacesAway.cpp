#include <vector>
using namespace std;

class Solution
{
public:
	bool kLengthApart(vector<int>& nums, int k)
	{
		int dis = k;
		for (auto n : nums)
		{
			if (n == 0)
				dis++;
			else
			{
				if (dis < k)
					return false;
				dis = 0;
			}
		}
		return true;
	}
};
