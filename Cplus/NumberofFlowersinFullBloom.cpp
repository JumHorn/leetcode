#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
	{
		map<int, int> m;
		for (auto &flower : flowers)
		{
			++m[flower[0]];
			--m[flower[1] + 1];
		}
		int N = persons.size();
		vector<pair<int, int>> v; //{time,index}
		for (int i = 0; i < N; ++i)
			v.push_back({persons[i], i});
		sort(v.begin(), v.end());
		vector<int> res(N);
		int bloom = 0, i = 0;
		for (auto it = m.begin(); i < N;)
		{
			for (; it != m.end() && v[i].first >= it->first; ++it)
				bloom += it->second;
			if (it == m.end())
				break;
			for (; i < N && v[i].first < it->first; ++i)
				res[v[i].second] = bloom;
		}
		return res;
	}
};