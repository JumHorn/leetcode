#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
	{
		int M = spells.size(), N = potions.size();
		vector<pair<int, int>> sp;
		for (int i = 0; i < M; ++i)
			sp.push_back({spells[i], i});
		sort(sp.begin(), sp.end());
		sort(potions.begin(), potions.end());
		vector<int> res(M);
		for (int i = 0, j = N - 1; i < M; ++i)
		{
			while (j >= 0 && (long long)sp[i].first * potions[j] >= success)
				--j;
			res[sp[i].second] = N - j - 1;
		}
		return res;
	}
};