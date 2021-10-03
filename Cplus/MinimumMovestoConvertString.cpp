#include <string>
using namespace std;

class Solution
{
public:
	int minimumMoves(string s)
	{
		int N = s.length(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == 'X')
			{
				++res;
				i += 2;
			}
		}
		return res;
	}
};