#include <climits>
#include <vector>
using namespace std;

/*
Given a target sum x, each pair of nums[i] and nums[n-1-i]
would either need 0, 1, or 2 modifications

final sum is T,how much modification do we need
1. 2 <= T < min(A, B) + 1, we need 2 operations to make both A, B smaller
2. min(A, B) + 1 <= T < A + B, we need 1 operation to make the larger one out of A and B smaller
3. T = A + B, we need 0 operation
4. A + B < T < max(A, B) + limit, we need 1 operation to make the smaller one out of A and B larger
5. max(A, B) + limit < T <= 2 * limit, we need 2 operation to make both A, B larger
*/

class Solution
{
public:
	int minMoves(vector<int> &nums, int limit)
	{
		int N = nums.size();
		vector<int> modification(2 * limit + 2); //{sum as index,modification count as value}
		for (int i = 0; i < N / 2; ++i)
		{
			int a = nums[i], b = nums[N - i - 1];
			modification[2] += 2;
			--modification[min(a, b) + 1];
			--modification[a + b];
			++modification[a + b + 1];
			++modification[max(a, b) + limit + 1];
		}
		int res = INT_MAX, prefixsum = 0;
		for (int i = 2; i <= 2 * limit; ++i)
		{
			prefixsum += modification[i];
			res = min(res, prefixsum);
		}
		return res;
	}
};