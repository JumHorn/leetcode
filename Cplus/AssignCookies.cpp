#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findContentChildren(vector<int> &g, vector<int> &s)
	{
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int res = 0, M = g.size(), N = s.size();
		for (int i = M - 1, j = N - 1; i >= 0 && j >= 0; --i)
		{
			if (s[j] >= g[i])
			{
				++res;
				--j;
			}
		}
		return res;
	}
};