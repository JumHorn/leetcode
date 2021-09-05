#include <vector>
using namespace std;

class Solution
{
public:
	int countQuadruplets(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		for (int a = 0; a < N; ++a)
		{
			for (int b = a + 1; b < N; ++b)
			{
				for (int c = b + 1; c < N; ++c)
				{
					for (int d = c + 1; d < N; ++d)
					{
						if (nums[d] == nums[a] + nums[b] + nums[c])
							++res;
					}
				}
			}
		}
		return res;
	}
};