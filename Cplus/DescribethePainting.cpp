#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
	{
		int N = 1e5 + 3;
		vector<long long> range(N);
		vector<bool> breakpoint(N);
		for (auto &seg : segments)
		{
			range[seg[0]] += seg[2];
			range[seg[1]] -= seg[2];
			breakpoint[seg[0]] = breakpoint[seg[1]] = true;
		}
		for (int i = 1; i < N; ++i)
			range[i] += range[i - 1];
		vector<vector<long long>> res;
		for (int i = 0; i < N; ++i)
		{
			if (range[i] > 0)
			{
				int j = i + 1;
				while (range[i] == range[j] && !breakpoint[j])
					++j;
				res.push_back({i, j, range[i]});
				i = j - 1; //reduce for next ++i
			}
		}
		return res;
	}
};