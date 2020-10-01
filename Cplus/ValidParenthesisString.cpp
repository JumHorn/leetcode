#include <string>
using namespace std;

class Solution
{
public:
	bool checkValidString(string s)
	{
		int low = 0, high = 0; //the number of left bracket in range [low,high]
		for (auto c : s)
		{
			if (c == '(')
				++low;
			else if (low > 0)
				--low;

			if (c == ')')
				--high;
			else
				++high;
			if (high < 0)
				return false;
		}
		return low == 0;
	}
};