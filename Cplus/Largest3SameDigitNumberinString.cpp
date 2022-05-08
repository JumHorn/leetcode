#include <string>
using namespace std;

class Solution
{
public:
	string largestGoodInteger(string num)
	{
		int N = num.length();
		string res;
		for (int i = 0; i <= N - 3; ++i)
		{
			if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
			{
				if (res < num.substr(i, 3))
					res = num.substr(i, 3);
			}
		}
		return res;
	}
};