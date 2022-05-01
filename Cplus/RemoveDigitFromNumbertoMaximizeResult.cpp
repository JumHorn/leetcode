#include <string>
using namespace std;

class Solution
{
public:
	string removeDigit(string number, char digit)
	{
		string res;
		int N = number.length();
		for (int i = 0; i < N; ++i)
		{
			if (number[i] == digit)
			{
				string val = number.substr(0, i) + number.substr(i + 1);
				if (val >= res)
					res = val;
			}
		}
		return res;
	}
};