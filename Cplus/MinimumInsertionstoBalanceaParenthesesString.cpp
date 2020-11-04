#include <string>
using namespace std;

class Solution
{
public:
	int minInsertions(string s)
	{
		int right = 0, res = 0;
		for (auto c : s)
		{
			if (c == '(')
			{
				if (right % 2 > 0)
				{
					--right;
					++res;
				}
				right += 2;
			}
			else
			{
				--right;
				if (right < 0)
				{
					right += 2;
					++res;
				}
			}
		}
		return res + right;
	}
};