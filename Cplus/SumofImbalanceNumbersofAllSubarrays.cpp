#include <vector>
using namespace std;

class Solution
{
public:
	int sumImbalanceNumbers(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		vector<int> seen(N + 2, -1), left(N);
		for (int i = 0; i < N; ++i)
		{
			left[i] = max(seen[nums[i]], seen[nums[i] + 1]);
			seen[nums[i]] = i;
		}
		fill(seen.begin(), seen.end(), N);
		for (int i = N - 1; i >= 0; --i)
		{
			seen[nums[i]] = i;
			res += (i - left[i]) * (seen[nums[i] + 1] - i);
		}
		return res - N * (N + 1) / 2;
	}
};