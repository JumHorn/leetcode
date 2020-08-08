#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canConvertString(string s, string t, int k)
	{
		vector<int> moves(26);
		int base = k / 26, r = k % 26;
		for (int i = 0; i < 26; ++i)
			moves[i] = base;
		for (int i = 0; i < r; ++i)
			++moves[i];
		if (s.length() != t.length())
			return false;
		for (int i = 0; i < (int)s.length(); ++i)
		{
			if (s[i] != t[i])
			{
				int steps = (t[i] - s[i] + 26) % 26 - 1;
				if (moves[steps] == 0)
					return false;
				--moves[steps];
			}
		}
		return true;
	}
};
