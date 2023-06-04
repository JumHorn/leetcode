#include <vector>
using namespace std;

class Solution
{
public:
	int semiOrderedPermutation(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		int first, last;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == 1)
				first = i;
			else if (nums[i] == N)
				last = i;
		}
		if (first > last)
		{
			res += first - last;
			int tmp = last;
			first = last;
			last = tmp + 1;
		}
		return res + first + N - 1 - last;
	}
};