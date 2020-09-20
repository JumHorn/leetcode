#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &nums)
	{
		int N = nums.size();
		vector<string> v(nums.size());
		for (int i = 0; i < N; i++)
			v[i] = to_string(nums[i]);
		sort(v.begin(), v.end(), *this);
		string res;
		for (auto &str : v)
			res += str;
		return res[0] == '0' ? "0" : res;
	}

	bool operator()(const string &lhs, const string &rhs)
	{
		return lhs + rhs > rhs + lhs;
	}
};