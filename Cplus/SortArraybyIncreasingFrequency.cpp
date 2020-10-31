#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> frequencySort(vector<int> &nums)
	{
		unordered_map<int, int> m; //{value,count}
		for (auto n : nums)
			++m[n];
		auto lambda = [&](int lhs, int rhs) {
			if (m[lhs] != m[rhs])
				return m[lhs] < m[rhs];
			return lhs > rhs;
		};
		sort(nums.begin(), nums.end(), lambda);
		return nums;
	}
};