#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
	{
		hFences.push_back(1);
		hFences.push_back(m);
		vFences.push_back(1);
		vFences.push_back(n);
		sort(hFences.begin(), hFences.end());
		sort(vFences.begin(), vFences.end());

		int h = hFences.size(), v = vFences.size();
		unordered_set<int> s; //{ranges available}
		for (int i = 0; i < v; ++i)
		{
			for (int j = i + 1; j < v; ++j)
				s.insert(vFences[j] - vFences[i]);
		}
		long long res = -1;
		for (int i = 0; i < h; ++i)
		{
			for (int j = i + 1; j < h; ++j)
			{
				if (s.find(hFences[j] - hFences[i]) != s.end())
					res = max(res, (long long)(hFences[j] - hFences[i]) * (hFences[j] - hFences[i]));
			}
		}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};