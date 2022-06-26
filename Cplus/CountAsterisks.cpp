#include <string>
using namespace std;

class Solution
{
public:
	int countAsterisks(string s)
	{
		int open = 0, res = 0;
		for (auto c : s)
		{
			if (c == '|')
				open = 1 - open;
			if (open == 0 && c == '*')
				++res;
		}
		return res;
	}
};