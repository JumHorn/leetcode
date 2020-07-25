#include <algorithm>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution
{
public:
	int shortestSubarray(vector<int> &A, int K)
	{
		int res = INT_MAX, N = A.size();
		vector<int> sums(N + 1);
		deque<int> monoqueue;
		for (int i = 0; i < N; i++)
			sums[i + 1] = sums[i] + A[i];
		monoqueue.push_back(0);
		for (int i = 1; i <= N; i++)
		{
			while (!monoqueue.empty() && sums[i] - sums[monoqueue.front()] >= K)
			{
				res = min(res, i - monoqueue.front());
				monoqueue.pop_front();
			}
			while (!monoqueue.empty() && sums[i] <= sums[monoqueue.back()])
				monoqueue.pop_back();
			monoqueue.push_back(i);
		}
		return res == INT_MAX ? -1 : res;
	}
};