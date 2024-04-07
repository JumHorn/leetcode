#include <string>
using namespace std;

class Solution
{
public:
	string getSmallestString(string s, int k)
	{
		for (auto &n : s)
		{
			for (char c = 'a'; c <= 'z'; ++c)
			{
				int d = min((n - c + 26) % 26, (c - n + 26) % 26);
				if (k >= d)
				{
					k -= d;
					n = c;
					break;
				}
			}
			if (k <= 0)
				break;
		}
		return s;
	}
};