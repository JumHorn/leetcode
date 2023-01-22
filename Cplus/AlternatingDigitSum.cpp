#include <string>
using namespace std;

class Solution
{
public:
	int alternateDigitSum(int n)
	{
		string val = to_string(n);
		int res = 0, pos = 1;
		for (auto c : val)
		{
			res += (c - '0') * pos;
			pos = -pos;
		}
		return res;
	}
};