#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int tupleSameProduct(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), res = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
				++m[nums[i] * nums[j]];
		}
		for (auto &n : m)
			res += n.second * (n.second - 1) / 2 * 8;
		return res;
	}
};