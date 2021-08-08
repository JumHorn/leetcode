#include <string>
using namespace std;

class Solution
{
public:
	string makeFancyString(string s)
	{
		string res;
		char pre = '\0';
		int count = 0;
		for (auto c : s)
		{
			if (pre == c)
				++count;
			else
			{
				res += string(min(2, count), pre);
				pre = c;
				count = 1;
			}
		}
		res += string(min(2, count), pre);
		return res;
	}
};