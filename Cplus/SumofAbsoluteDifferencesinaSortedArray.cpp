#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getSumAbsoluteDifferences(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> prefixsum(N + 1), res(N);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];
		for (int i = 0; i < N; ++i)
			res[i] = (nums[i] * i - prefixsum[i]) + prefixsum[N] - prefixsum[i + 1] - (N - i - 1) * nums[i];
		return res;
	}
};