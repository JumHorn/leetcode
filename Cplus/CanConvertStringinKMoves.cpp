#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canConvertString(string s, string t, int k)
	{
		if (s.length() != t.length())
			return false;
		int base = k / 26, r = k % 26;
		vector<int> moves(26, base);
		for (int i = 0; i < r; ++i)
			++moves[i];
		for (int i = 0; i < (int)s.length(); ++i)
		{
			if (s[i] != t[i])
			{
				int steps = (t[i] - s[i] + 26) % 26 - 1;
				if (--moves[steps] < 0)
					return false;
			}
		}
		return true;
	}
};