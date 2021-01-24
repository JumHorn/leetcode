#include <bitset>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
	{
		static const int BIT = 512;
		int res = friendships.size();
		vector<bitset<BIT>> lan;
		for (auto &l : languages)
		{
			lan.emplace_back();
			for (auto n : l)
				lan.back().set(n);
		}

		for (int l = 1; l <= n; ++l)
		{
			unordered_set<int> s;
			for (auto &f : friendships)
			{
				if ((lan[f[0] - 1] & lan[f[1] - 1]).any())
					continue;
				if (!lan[f[0] - 1].test(l))
					s.insert(f[0]);
				if (!lan[f[1] - 1].test(l))
					s.insert(f[1]);
			}
			res = min(res, (int)s.size());
		}
		return res;
	}
};