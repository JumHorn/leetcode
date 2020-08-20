#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestDupSubstring(string S)
	{
		int lo = 0, hi = S.length(), res = 0;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int index = validate(S, mi);
			if (index >= 0)
			{
				lo = mi + 1;
				res = index;
			}
			else
				hi = mi;
		}
		if (lo == 0)
			return "";
		return S.substr(res, lo - 1);
	}

	int validate(const string &S, int len)
	{
		unordered_map<long, vector<int>> m; //{hash,index}
		long hash = 0, p = 1;
		for (int i = 0; i < len; ++i)
			hash = (hash * PRIMER + S[i]) % MOD;
		for (int i = 0; i < len - 1; ++i)
			p = p * PRIMER % MOD;
		m[hash].push_back(0);

		for (int i = len; i < (int)S.length(); ++i)
		{
			hash = (hash - (S[i - len]) * p % MOD + MOD) % MOD;
			hash = (hash * PRIMER + S[i]) % MOD;
			if (m.find(hash) != m.end())
			{
				for (auto index : m[hash])
				{
					if (S.substr(index, len) == S.substr(i - len + 1, len))
						return index;
				}
			}
			m[hash].push_back(i - len + 1);
		}
		return -1;
	}

private:
	static const int MOD = 1e9 + 7;
	static const int PRIMER = 31;
};