#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countConsistentStrings(string allowed, vector<string> &words)
	{
		int mask = 0, res = 0;
		for (auto c : allowed)
			mask |= 1 << (c - 'a');
		for (auto str : words)
		{
			if (isAllowed(mask, str))
				++res;
		}
		return res;
	}

	bool isAllowed(int mask, string &str)
	{
		for (auto c : str)
		{
			if ((mask & (1 << (c - 'a'))) == 0)
				return false;
		}
		return true;
	}
};