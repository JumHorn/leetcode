#include <string>
using namespace std;

class Solution
{
public:
	string removeTrailingZeros(string num)
	{
		int N = num.size(), i = N - 1;
		while (i > 0 && num[i] == '0')
			--i;
		return num.substr(0, i + 1);
	}
};