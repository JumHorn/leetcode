#include <vector>
using namespace std;

class Solution
{
public:
	int countHillValley(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		vector<int> v;
		v.push_back(nums[0]);
		//remove dumplicate
		for (auto n : nums)
		{
			if (v.back() != n)
				v.push_back(n);
		}

		for (int i = 1; i < (int)v.size() - 1; ++i)
		{
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) //hill
				++res;
			else if (v[i] < v[i - 1] && v[i] < v[i + 1]) //valley
				++res;
		}
		return res;
	}
};