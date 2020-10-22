#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int maxRepOpt1(string text)
	{
		unordered_map<char, int> window, count;
		for (auto n : text)
			++count[n];
		int i, j;
		for (i = 0, j = 0; j < (int)text.length(); ++j)
		{
			++window[text[j]];
			if (window.size() > 2)
			{
				if (--window[text[i]] == 0)
					window.erase(text[i]);
				++i;
			}
			else if (window.size() == 2)
			{
				auto iter = window.begin();
				char a = iter->first, b = (++iter)->first;
				if (!((window[a] == j - i && count[a] > j - i) ||
					  (window[b] == j - i && count[b] > j - i)))
				{
					if (--window[text[i]] == 0)
						window.erase(text[i]);
					++i;
				}
			}
		}
		return j - i;
	}
};