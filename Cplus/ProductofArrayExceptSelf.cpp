#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> productExceptSelf(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> prefix(N + 1), suffix(N + 1);
		prefix[0] = suffix[N] = 1;
		for (int i = 0; i < N; ++i)
		{
			prefix[i + 1] = prefix[i] * nums[i];
			suffix[N - i - 1] = suffix[N - i] * nums[N - i - 1];
		}
		for (int i = 0; i < N; ++i)
			nums[i] = prefix[i] * suffix[i + 1];
		return nums;
	}
};