#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSteps(string s, string t)
	{
		unordered_map<char, int> m; //{char,count}
		for (int i = 0; i < (int)s.length(); ++i)
		{
			++m[s[i]];
			--m[t[i]];
		}
		int res = 0;
		for (auto &n : m)
		{
			if (n.second > 0)
				res += n.second;
		}
		return res;
	}
};