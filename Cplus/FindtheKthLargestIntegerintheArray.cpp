#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string kthLargestNumber(vector<string> &nums, int k)
	{
		auto f = [](const string &lhs, const string &rhs)
		{
			if (lhs.length() != rhs.length())
				return lhs.length() > rhs.length();
			return lhs > rhs;
		};
		sort(nums.begin(), nums.end(), f);
		return nums[k - 1];
	}
};