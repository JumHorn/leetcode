#include <string>
using namespace std;

class Solution
{
public:
	bool checkString(string s)
	{
		bool flag = true;
		for (auto c : s)
		{
			if (c == 'b')
				flag = false;
			if (c == 'a')
			{
				if (flag == false)
					return false;
			}
		}
		return true;
	}
};