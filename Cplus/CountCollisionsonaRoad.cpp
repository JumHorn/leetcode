#include <string>
using namespace std;

class Solution
{
public:
	int countCollisions(string directions)
	{
		int r = 0, s = 0, res = 0;
		for (auto c : directions)
		{
			if (c == 'L')
			{
				if (r > 0)
				{
					res += 2;
					--r;
					s = 1;
					res += r;
					r = 0;
				}
				else if (s != 0)
					++res;
			}
			else if (c == 'R')
				++r;
			else
			{
				s = 1;
				res += r;
				r = 0;
			}
		}
		return res;
	}
};