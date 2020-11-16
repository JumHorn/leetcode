#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> kthSmallestPrimeFraction(vector<int> &A, int K)
	{
		int N = A.size();
		auto f = [&](int *lhs, int *rhs) {
			return A[lhs[0]] * A[rhs[1]] > A[lhs[1]] * A[rhs[0]];
		};
		priority_queue<int *, vector<int *>, decltype(f)> q(f);
		for (int i = 0; i < N - 1; ++i)
			q.push(new int[2]{i, N - 1});
		while (--K > 0)
		{
			int *top = q.top();
			q.pop();
			if (top[0] < top[1] - 1)
			{
				--top[1];
				q.push(top);
			}
		}
		return {A[q.top()[0]], A[q.top()[1]]};
	}
};