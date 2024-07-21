#include <string>
using namespace std;

class Solution
{
public:
	int maxOperations(string s)
	{
		int N = s.size(), res = 0, ones = 0;
		for (int i = 0, j = 0; j <= N; ++j)
		{
			if (j == N || s[j] == '1')
			{
				if (j - i - 1 > 0)
					res += ones;
				i = j;
				++ones;
			}
		}
		return res;
	}
};