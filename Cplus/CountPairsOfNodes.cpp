#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
degree[a] + degree[b] - overlap[a][b] > query
由于是稀松图，overlap数组过大
所以可以用map<int,int>表示图,将a*n+b作为key
*/

class Solution
{
public:
	vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
	{
		vector<int> degree(n + 1), sortedDeg;
		unordered_map<int, int> overlap; //{point,count}
		vector<pair<int, int>> distinctEdges;
		auto encode = [n](int a, int b) { return max(a, b) * n + min(a, b); };
		for (auto &edge : edges)
		{
			int p = edge[0], q = edge[1];
			++degree[p];
			++degree[q];
			int key = encode(p, q);
			if (overlap.find(key) == overlap.end())
				distinctEdges.push_back({p, q});
			++overlap[key];
		}
		sortedDeg = {degree.begin() + 1, degree.end()};
		sort(sortedDeg.begin(), sortedDeg.end());
		int N = queries.size();
		vector<int> res(N);
		for (int i = 0; i < N; ++i)
		{
			for (int l = 0, r = n - 1; l < n; ++l)
			{
				while (r > l && sortedDeg[l] + sortedDeg[r] > queries[i])
					--r;
				res[i] += n - max(l, r) - 1;
			}
			for (auto &edge : distinctEdges)
			{
				int p = edge.first, q = edge.second;
				int key = encode(p, q);
				if (degree[p] + degree[q] > queries[i] && degree[p] + degree[q] - overlap[key] <= queries[i])
					--res[i];
			}
		}
		return res;
	}
};