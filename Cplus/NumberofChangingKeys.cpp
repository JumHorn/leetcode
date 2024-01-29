#include <string>
using namespace std;

class Solution
{
public:
	int countKeyChanges(string s)
	{
		int res = 0;
		char pre = '\0';
		for (auto c : s)
		{
			char v = tolower(c);
			if (pre != v)
			{
				pre = v;
				++res;
			}
		}
		return res - 1;
	}
};