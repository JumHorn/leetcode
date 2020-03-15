#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
	{
		static const int MOD = 1e9 + 7;
		vector<vector<long long>> v;
		vector<int> heap(k);
		for (int i = 0; i < n; i++)
			v.push_back({efficiency[i], speed[i]});
		sort(v.begin(), v.end(), greater<vector<long long>>());
		long long res = 0, s = 0;
		for (int i = 0; i < k; i++)
		{
			heap[i] = v[i][1];
			s += v[i][1];
			res = max(res, v[i][0] * s);
		}
		make_heap(heap.begin(), heap.end(), greater<int>());
		pop_heap(heap.begin(), heap.end(), greater<int>());
		for (int i = k; i < n; i++)
		{
			if (v[i][1] > heap.back())
			{
				s = s - heap.back() + v[i][1];
				heap.back() = v[i][1];
				res = max(res, v[i][0] * s);
				push_heap(heap.begin(), heap.end(), greater<int>());
				pop_heap(heap.begin(), heap.end(), greater<int>());
			}
		}
		return res % MOD;
	}
};
