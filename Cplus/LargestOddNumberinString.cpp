#include <string>
using namespace std;

class Solution
{
public:
	string largestOddNumber(string num)
	{
		int N = num.length();
		for (--N; N >= 0; --N)
		{
			if (((num[N] - '0') % 2) == 1)
				break;
		}
		return num.substr(0, N + 1);
	}
};