#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &nums)
	{
		vector<string> v;
		for (auto n : nums)
			v.push_back(to_string(n));
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