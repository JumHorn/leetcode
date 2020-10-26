#include <string>
using namespace std;

class Solution
{
public:
	bool repeatedSubstringPattern(string s)
	{
		int N = s.length();
		for (int i = 1; i <= N / 2; ++i)
		{
			if (N % i == 0)
			{
				int j = i;
				for (; j < N; j += i)
				{
					if (s.compare(0, i, s, j, i) != 0)
						break;
				}
				if (j == N)
					return true;
			}
		}
		return false;
	}
};