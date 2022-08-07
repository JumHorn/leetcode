#include <vector>
using namespace std;

class Solution
{
public:
	int arithmeticTriplets(vector<int> &nums, int diff)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int j = i, k = i;
			while (j < N && nums[i] + diff > nums[j])
				++j;
			if (j < N && nums[i] + diff == nums[j])
			{
				while (k < N && nums[j] + diff > nums[k])
					++k;
				if (k < N && nums[j] + diff == nums[k])
					++res;
			}
		}
		return res;
	}
};