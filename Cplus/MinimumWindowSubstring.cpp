#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		vector<int> count('z' - 'A' + 1);
		for (auto c : t)
			++count[c - 'A'];
		int N = s.length(), n = t.length();
		int start = -1, window = N + 1;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (--count[s[i] - 'A'] >= 0)
				--n;
			while (n == 0)
			{
				if (i - j + 1 < window)
				{
					start = j;
					window = i - j + 1;
				}
				if (++count[s[j++] - 'A'] > 0)
					++n;
			}
		}
		return start >= 0 ? s.substr(start, window) : "";
	}
};