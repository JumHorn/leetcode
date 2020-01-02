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
		int minchar[26] = {0}, mincount = 0;
		unordered_map<string, int> strmap;
		int res = 0;
		for (int i = 0; i < minSize - 1; i++)
			if (++minchar[s[i] - 'a'] == 1)
				++mincount;
		for (int i = minSize - 1; i < (int)s.length(); i++)
		{
			if (++minchar[s[i] - 'a'] == 1)
				++mincount;
			if (mincount <= maxLetters)
			{
				res = max(res, ++strmap[s.substr(i - minSize + 1, minSize)]);
				int maxchar[26] = {0};
				int maxcount = mincount;
				memcpy((char*)&maxchar, (char*)&minchar, 26 * sizeof(int));
				for (int j = i + 1; j < (int)s.length(); j++)
				{
					if (j - i + minSize < maxSize)
					{
						if (++maxchar[s[j] - 'a'] == 1)
							++maxcount;
						if (maxcount <= maxLetters)
							res = max(res, ++strmap[s.substr(i - minSize + 1, minSize + j - i)]);
						else
							break;
					}
					else
						break;
				}
			}
			if (--minchar[s[i - minSize + 1] - 'a'] == 0)
				--mincount;
		}
		return res;
	}
};
