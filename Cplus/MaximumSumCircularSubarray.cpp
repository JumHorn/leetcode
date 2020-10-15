#include <algorithm>
#include <climits>
#include <deque>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSubarraySumCircular(vector<int> &A)
	{
		int N = A.size(), res = INT_MIN;
		vector<int> sum(2 * N + 1);
		for (int i = 1; i <= 2 * N; ++i)
		{
			if (i <= N)
				sum[i] = sum[i - 1] + A[i - 1];
			else
				sum[i] = sum[i - 1] + A[i - N - 1];
		}
		deque<int> monoqueue;
		monoqueue.push_back(0);
		for (int i = 1; i <= 2 * N; ++i)
		{
			if (!monoqueue.empty() && i - monoqueue.front() > N)
				monoqueue.pop_front();
			res = max(res, sum[i] - sum[monoqueue.front()]);
			while (!monoqueue.empty() && sum[i] <= sum[monoqueue.back()])
				monoqueue.pop_back();
			monoqueue.push_back(i);
		}
		return res;
	}
};