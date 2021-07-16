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
		int start = -1, i = 0, j = 0;
		for (; i < N; ++i)
		{
			if (--count[s[i] - 'A'] >= 0)
				--n;
			if (start != -1)
			{
				if (++count[s[j] - 'A'] > 0)
					++n;
				++j;
			}
			for (; n == 0; ++j)
			{
				start = j;
				if (++count[s[j] - 'A'] > 0)
					++n;
			}
		}
		return start >= 0 ? s.substr(start, i - j + 1) : "";
	}
};