#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	int minimumSwap(string s1, string s2)
	{
		int x1 = 0, y1 = 0;
		for (int i = 0; i < (int)s1.length(); ++i)
		{
			if (s1[i] != s2[i])
				s1[i] == 'x' ? x1++ : y1++;
		}
		if ((x1 + y1) % 2 != 0)
			return -1;
		return (x1 + y1) / 2 + x1 % 2;
	}
};
