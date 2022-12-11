#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumValue(vector<string> &strs)
	{
		long long res = 0;
		for (auto &str : strs)
		{
			if (isdigits(str))
				res = max(res, stoll(str));
			else
				res = max(res, (long long)str.size());
		}
		return res;
	}

	bool isdigits(string &s)
	{
		for (auto c : s)
		{
			if (c < '0' || c > '9')
				return false;
		}
		return true;
	}
};