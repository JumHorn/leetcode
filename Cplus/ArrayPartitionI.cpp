#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int arrayPairSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int sum = 0, N = nums.size();
		for (int i = 0; i < N; i += 2)
			sum += nums[i];
		return sum;
	}
};