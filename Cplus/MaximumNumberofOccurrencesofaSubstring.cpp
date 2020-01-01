#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxFreq(string s, int maxLetters, int minSize, int maxSize)
	{
		unordered_map<char, int> maxchar, minchar;
		unordered_map<string, int> strmap;
		int res = 0;
		for (int i = 0; i < minSize - 1; i++)
			++minchar[s[i]];
		for (int i = minSize - 1; i < (int)s.length(); i++)
		{
			++minchar[s[i]];
			if ((int)minchar.size() <= maxLetters)
			{
				res = max(res, ++strmap[s.substr(i - minSize + 1, minSize)]);
				unordered_map<char, int> maxchar = minchar;
				for (int j = i + 1; j < (int)s.length(); j++)
				{
					if (j - i + minSize < maxSize)
					{
						if (++maxchar[s[j]] <= maxLetters)
							res = max(res, ++strmap[s.substr(i - minSize + 1, minSize + j - i)]);
						else
							break;
					}
					else
						break;
				}
			}
			if (--minchar[s[i - minSize + 1]] == 0)
				minchar.erase(s[i - minSize + 1]);
		}
		return res;
	}
};
