#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string optimalDivision(vector<int> &nums)
	{
		string res = to_string(nums[0]);
		if (nums.size() == 1)
			return res;
		if (nums.size() == 2)
			return res + "/" + to_string(nums[1]);
		res += "/(";
		for (int i = 1; i < (int)nums.size() - 1; ++i)
		{
			res += to_string(nums[i]);
			res += "/";
		}
		res += to_string(nums.back()) + ")";
		return res;
	}
};
