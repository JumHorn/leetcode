#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumOperations(string num)
	{
		vector<string> suf = {"00", "25", "50", "75"};
		int res = INT_MAX;
		for (auto s : suf)
			res = min(res, calc(num, s));
		return res;
	}

	int calc(string &num, string &suf)
	{
		int i = (int)num.size() - 1, j = (int)suf.size() - 1, res = 0;
		for (; i >= 0 && j >= 0; --i)
		{
			if (num[i] == suf[j])
				--j;
			else
				++res;
		}
		return res + (i < 0 && j == 0 && suf[1] != '0' ? 1 : 0);
	}
};