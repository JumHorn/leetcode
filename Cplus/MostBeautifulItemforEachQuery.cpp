#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
	{
		int N = queries.size();
		vector<int> res(N);
		sort(items.begin(), items.end());
		vector<pair<int, int>> v; //{price,index}
		for (int i = 0; i < N; ++i)
			v.push_back({queries[i], i});
		sort(v.begin(), v.end());
		int beauty = 0;
		for (int i = 0, j = 0; i < N; ++i)
		{
			for (; j < (int)items.size() && items[j][0] <= v[i].first; ++j)
				beauty = max(beauty, items[j][1]);
			res[v[i].second] = beauty;
		}
		return res;
	}
};