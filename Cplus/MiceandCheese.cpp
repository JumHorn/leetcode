#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
	{
		int N = reward1.size(), res = 0;
		vector<pair<int, int>> v; //{diff,index}
		for (int i = 0; i < N; ++i)
			v.push_back({reward1[i] - reward2[i], i});
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		for (int i = 0; i < k; ++i)
		{
			res += reward1[v[i].second];
			reward1[v[i].second] = -1;
		}
		for (int i = 0; i < N; ++i)
		{
			if (reward1[i] >= 0)
				res += reward2[i];
		}
		return res;
	}
};