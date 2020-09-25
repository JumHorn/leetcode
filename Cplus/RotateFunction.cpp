#include <climits>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxRotateFunction(vector<int> &A)
	{
		long sum = accumulate(A.begin(), A.end(), 0L);
		long res = INT_MIN, n = A.size(), value = 0;
		for (int i = 0; i < n; i++)
			value += i * A[i];
		res = value;
		for (int i = 1; i < n; i++)
		{
			value = value + sum - n * A[n - i];
			res = max(res, value);
		}
		return res;
	}
};