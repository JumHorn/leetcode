#include <string>
using namespace std;

class Solution
{
public:
	bool checkOnesSegment(string s)
	{
		int one = 0;
		for (auto c : s)
			one += c - '0';
		bool flag = false;
		for (auto c : s)
		{
			if (c == '1')
			{
				--one;
				flag = true;
			}
			if (flag && c == '0')
				return one == 0;
		}
		return one == 0;
	}
};