#include <string>
using namespace std;

class Solution
{
public:
	int minimumDeletions(string s)
	{
		int a = 0;
		for (auto c : s)
		{
			if (c == 'a')
				++a;
		}
		int b = 0, res = a;
		for (auto c : s)
		{
			c == 'a' ? --a : ++b;
			res = min(res, a + b);
		}
		return res;
	}
};