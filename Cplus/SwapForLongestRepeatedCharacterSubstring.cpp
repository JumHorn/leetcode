#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int maxRepOpt1(string text)
	{
		int charmap[26] = {0};
		for (auto n : text)
			charmap[n - 'a']++;
		int res = 1;
		unordered_map<char, int> m;
		for (int i = 0, j = 0; i < (int)text.length(); i++)
		{
			++m[text[i]];
			if (m.size() == 2)
			{
				auto iter = m.begin();
				char a = iter->first;
				++iter;
				char b = iter->first;
				if (m[a] == 1 || m[b] == 1)
				{
					if (m[b] < charmap[b - 'a'])
						res = max(res, i - j + 1);
					if (m[a] < charmap[a - 'a'])
						res = max(res, i - j + 1);
				}
				else
				{
					if (--m[text[j]] == 0)
						m.erase(text[j]);
					j++;
				}
			}
			else if (m.size() == 1)
				res = max(res, i - j + 1);
			else
			{
				if (--m[text[j]] == 0)
					m.erase(text[j]);
				j++;
			}
		}
		return res;
	}
};
