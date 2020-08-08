#include <string>
using namespace std;

class Solution
{
public:
	int minInsertions(string s)
	{
		int N = s.length(), left = 0, right = 0, res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '(')
			{
				if (right != 0)
				{
					if (right == 1)
					{
						if (left != 0)
						{
							--left;
							++res;
						}
						else
							res += 2;
					}
					else
					{
						if (left == 0)
							++res;
					}
					right = 0;
				}
				++left;
			}
			else
			{
				++right;
				if (right == 2)
				{
					if (left == 0)
						++res;
					else
						--left;
					right = 0;
				}
			}
		}
		if (left == 0 && right == 1)
			return res + 2;
		return res + left * 2 - right;
	}
};