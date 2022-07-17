#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numberOfPairs(vector<int> &nums)
	{
		vector<int> count(101);
		for (auto n : nums)
			++count[n];
		int res = 0, N = nums.size();
		for (auto n : count)
			res += n / 2;
		return {res, N - res * 2};
	}
};