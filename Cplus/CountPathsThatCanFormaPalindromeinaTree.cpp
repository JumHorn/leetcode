#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countPalindromePaths(vector<int> &parent, string s)
	{
		long long res = 0, N = s.size();
		unordered_map<int, int> m;
		vector<int> mask(N); // accumulate bitmask from root to node i
		for (int i = 0; i < N; ++i)
		{
			int mask_to_root = getBitMask(parent, s, i, mask);
			for (int j = 0; j < 26; ++j)
			{
				if (m.find(mask_to_root ^ (1 << j)) != m.end())
					res += m[mask_to_root ^ (1 << j)];
			}
			res += m[mask_to_root]++;
		}
		return res;
	}

	int getBitMask(vector<int> &parent, string &s, int at, vector<int> &mask)
	{
		if (at > 0 && mask[at] == 0)
			mask[at] = getBitMask(parent, s, parent[at], mask) ^ (1 << (s[at] - 'a'));
		return mask[at];
	}
};