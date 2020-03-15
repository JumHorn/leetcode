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
		long long res = 0, s = 0, minindex = 0;
		for (int i = 0; i < k; i++)
		{
			heap[i] = v[i][1];
			if (heap[i] < heap[minindex])
				minindex = i;
			s += v[i][1];
			res = max(res, v[i][0] * s);
		}
		for (int i = k; i < n; i++)
		{
			if (v[i][1] > heap[minindex])
			{
				s = s - heap[minindex] + v[i][1];
				heap[minindex] = v[i][1];
				minindex = min_element(heap.begin(), heap.end()) - heap.begin();
				res = max(res, v[i][0] * s);
			}
		}
		return res % MOD;
	}
};
