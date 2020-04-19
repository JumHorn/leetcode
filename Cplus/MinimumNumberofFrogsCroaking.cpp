#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberOfFrogs(string croakOfFrogs)
	{
		unordered_map<char, int> m;
		m['c'] = 0;
		m['r'] = 1;
		m['o'] = 2;
		m['a'] = 3;
		m['k'] = 4;
		int state[4] = {0}, frog = 0, res = 0;
		for (auto c : croakOfFrogs)
		{
			if (m[c] == 0)
			{
				++state[0];
				if (++frog > res)
					res = frog;
			}
			else if (m[c] == 4)
			{
				if (--state[3] < 0)
					return -1;
				--frog;
			}
			else
			{
				if (--state[m[c] - 1] < 0)
					return -1;
				++state[m[c]];
			}
		}
		for (int i = 0; i < 4; i++)
			if (state[i] != 0)
				return -1;
		return res;
	}
};
