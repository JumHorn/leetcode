#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> shash(26), phash(26);
		int slen = s.length(), plen = p.length();
		if (plen > slen)
			return {};
		for (auto c : p)
			++phash[c - 'a'];
		for (int i = 0; i < plen; ++i)
			++shash[s[i] - 'a'];
		vector<int> res;
		if (shash == phash)
			res.push_back(0);
		for (int i = 0; i < slen - plen; ++i)
		{
			--shash[s[i] - 'a'];
			++shash[s[i + plen] - 'a'];
			if (shash == phash)
				res.push_back(i + 1);
		}
		return res;
	}
};