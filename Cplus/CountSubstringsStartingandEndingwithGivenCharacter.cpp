#include <string>
using namespace std;

class Solution
{
public:
	long long countSubstrings(string s, char c)
	{
		long long res = 0, prefix = 0;
		for (auto o : s)
		{
			if (o == c)
				res += ++prefix;
		}
		return res;
	}
};