#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long putMarbles(vector<int> &weights, int k)
	{
		int N = weights.size();
		vector<long long> v;
		for (int i = 1; i < N; ++i)
			v.push_back(weights[i] + weights[i - 1]);
		sort(v.begin(), v.end());
		long long maxval = 0, minval = 0;
		for (int i = 0; i < k - 1; ++i)
		{
			minval += v[i];
			maxval += v[N - 2 - i];
		}
		return maxval - minval;
	}
};