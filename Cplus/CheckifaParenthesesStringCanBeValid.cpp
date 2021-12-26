#include <string>
using namespace std;

class Solution
{
public:
	bool canBeValid(string s, string locked)
	{
		int N = s.length();
		if (N % 2 == 1)
			return false;
		int l = 0, r = 0; //count of left and right
		for (int i = 0; i < N; ++i)
		{
			if (locked[i] == '1')
			{
				if (s[i] == ')')
				{
					if (l > 0)
						--l;
					else if (--r < 0)
						return false;
				}
				else
					++l;
			}
			else
				++r;
		}

		l = r = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			if (locked[i] == '1')
			{
				if (s[i] == '(')
				{
					if (l > 0)
						--l;
					else if (--r < 0)
						return false;
				}
				else
					++l;
			}
			else
				++r;
		}

		return true;
	}
};