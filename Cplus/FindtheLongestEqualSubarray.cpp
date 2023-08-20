#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestEqualSubarray(vector<int> &nums, int k)
	{
		int i = 0, j = 0, maxsame = 0, N = nums.size();
		unordered_map<int, int> hash;
		for (; j < N; ++j)
		{
			++hash[nums[j]];
			maxsame = max(maxsame, hash[nums[j]]);
			if (j - i - maxsame >= k)
				--hash[nums[i++]];
		}
		return maxsame;
	}
};