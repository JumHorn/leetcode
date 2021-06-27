#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	long long wonderfulSubstrings(string word)
	{
		long long res = 0;
		unordered_map<int, int> m; //{mask,count}
		m[0] = 1;
		int mask = 0;
		for (auto c : word)
		{
			mask ^= (1 << (c - 'a'));
			res += m[mask];
			for (int i = 0; i < 10; ++i)
				res += m[mask ^ (1 << i)];
			++m[mask];
		}
		return res;
	}
};