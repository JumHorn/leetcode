#include <string>
using namespace std;

class Solution
{
public:
	int maxDepth(string s)
	{
		int res = 0, leftp = 0;
		for (auto c : s)
		{
			if (c == '(')
				++leftp;
			else if (c == ')')
				--leftp;
			res = max(res, leftp);
		}
		return res;
	}
};