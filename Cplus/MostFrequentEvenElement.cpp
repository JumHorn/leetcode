#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int mostFrequentEven(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), count = 0, res = -1;
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || nums[i] != nums[j])
			{
				if (nums[j] % 2 == 0 && count < i - j)
				{
					res = nums[j];
					count = i - j;
				}
				j = i;
			}
		}
		return res;
	}
};