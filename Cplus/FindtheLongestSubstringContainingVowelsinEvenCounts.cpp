#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
	int findTheLongestSubstring(string s)
	{
		unordered_map<char, int> bit;
		bit['a'] = 0;
		bit['e'] = 1;
		bit['i'] = 2;
		bit['o'] = 3;
		bit['u'] = 4;
		unordered_map<int, int> index;
		int len = s.length(), res = 0, tmp = 0;
		for (int i = 0; i < len; i++)
		{
			if (bit.find(s[i]) != bit.end())
			{
				tmp ^= (1 << bit[s[i]]);
				if (tmp == 0)
				{
					res = i + 1;
					index[0] = -1;
					continue;
				}
			}
			else
			{
				if (index.find(0) == index.end())
					index[0] = i - 1;
			}

			for (auto &t : index)
				if ((tmp ^ t.first) == 0)
					res = max(res, i - t.second);
			if (index.find(tmp) == index.end())
				index[tmp] = i;
		}
		return res;
	}
};