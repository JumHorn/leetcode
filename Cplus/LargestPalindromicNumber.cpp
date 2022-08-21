#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestPalindromic(string num)
	{
		vector<int> count(10);
		for (auto c : num)
			++count[c - '0'];
		string res;
		int mid = -1;
		for (int i = 9; i >= 0; --i)
		{
			if (count[i] > 1)
			{
				if (i != 0 || !res.empty())
				{
					res += string(count[i] / 2, '0' + i);
					count[i] %= 2;
				}
			}
			if (count[i] % 2 == 1)
				mid = max(mid, i);
		}
		string dup = res;
		reverse(dup.begin(), dup.end());
		if (mid == -1)
		{
			if (res.empty())
				return "0";
			return res + dup;
		}
		return res + char('0' + mid) + dup;
	}
};