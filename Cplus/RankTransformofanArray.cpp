#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> arrayRankTransform(vector<int> &arr)
	{
		if (arr.empty())
			return {};
		int N = arr.size();
		vector<pair<int, int>> v; //{value,index}
		for (int i = 0; i < N; ++i)
			v.push_back({arr[i], i});
		sort(v.begin(), v.end());
		arr[v[0].second] = 1;
		for (int i = 1, rank = 1; i < N; ++i)
		{
			if (v[i - 1].first < v[i].first)
				++rank;
			arr[v[i].second] = rank;
		}
		return arr;
	}
};