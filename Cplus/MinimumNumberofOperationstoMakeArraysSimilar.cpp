#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long makeSimilar(vector<int> &nums, vector<int> &target)
	{
		//odered by even/odd,then the num
		auto f = [](int lhs, int rhs)
		{
			if (lhs % 2 != rhs % 2)
				return lhs % 2 < rhs % 2;
			return lhs < rhs;
		};
		sort(nums.begin(), nums.end(), f);
		sort(target.begin(), target.end(), f);

		long long res = 0, N = nums.size();
		for (int i = 0; i < N; ++i)
			res += abs(nums[i] - target[i]);
		return res / 4;
	}
};