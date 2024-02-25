#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
	{
		int N = nums.size(), M = changeIndices.size();
		long long total = N + accumulate(nums.begin(), nums.end(), 0LL);
		int lo = N, hi = M + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (!canDo(nums, changeIndices, mi, total))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo >= M + 1 ? -1 : lo;
	}

	int canDo(vector<int> &nums, vector<int> &changeIndices, int size, long long total)
	{
		int N = nums.size(), M = changeIndices.size(), op = 0;							   // operations wait to complete
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{nums[i],i}
		unordered_map<int, int> m;														   //{val,index}
		vector<int> marked(N);
		for (int i = size - 1; i >= 0; --i)
			m[changeIndices[i]] = i;
		for (int i = size - 1; i >= 0; --i)
		{
			int index = changeIndices[i] - 1, val = nums[index];
			if (val <= 1 || m[changeIndices[i]] != i)
			{
				++op;
				continue;
			}
			if (op == 0)
			{
				if (q.empty() || val <= q.top().first)
				{
					++op;
					continue;
				}
				auto [topval, topindex] = q.top();
				q.pop();
				total += topval + 1;
				marked[topindex] = 0;
				op += 2;
			}
			q.push({val, index});
			marked[index] = 1;
			total -= val + 1;
			--op;
		}
		return op >= total;
	}
};