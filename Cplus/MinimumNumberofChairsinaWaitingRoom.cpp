#include <string>
using namespace std;

class Solution
{
public:
	int minimumChairs(string s)
	{
		int res = 0, chair = 0;
		for (auto c : s)
		{
			if (c == 'E')
			{
				if (chair == 0)
					++res;
				else
					--chair;
			}
			else
				++chair;
		}
		return res;
	}
};