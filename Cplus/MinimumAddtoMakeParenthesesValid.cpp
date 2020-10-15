#include <string>
using namespace std;

class Solution
{
public:
	int minAddToMakeValid(string S)
	{
		int left = 0, res = 0;
		for (auto c : S)
		{
			if (c == '(')
				++left;
			else
				left > 0 ? --left : ++res;
		}
		return res + left;
	}
};