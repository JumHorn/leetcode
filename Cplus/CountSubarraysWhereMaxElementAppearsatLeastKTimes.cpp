#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countSubarrays(vector<int> &nums, int k)
	{
		long long res = 0, N = nums.size(), maxval = *max_element(nums.begin(), nums.end());
		vector<long long> pos;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (nums[i] == maxval)
				pos.push_back(i);
		}
		int P = pos.size();
		for (int i = k - 1; i < P; ++i)
			res += (pos[i - k + 1] + 1) * ((i + 1 == P ? N : pos[i + 1]) - pos[i]);
		return res;
	}
};