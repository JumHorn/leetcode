#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> mostVisited(int n, vector<int> &rounds)
	{
		vector<int> v(n + 1);
		++v[rounds[0]];
		for (int i = 1; i < (int)rounds.size(); ++i)
		{
			int j = rounds[i - 1] + 1;
			if (j == n + 1)
				j = 1;
			int end = rounds[i] + 1;
			if (end == n + 1)
				end = 1;
			while (j != end)
			{
				++v[j];
				++j;
				if (j == n + 1)
					j = 1;
			}
		}
		int val = *max_element(v.begin(), v.end());
		vector<int> res;
		for (int i = 1; i <= n; ++i)
		{
			if (v[i] == val)
				res.push_back(i);
		}
		sort(res.begin(), res.end());
		return res;
	}
};