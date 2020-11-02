#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxRotateFunction(vector<int> &A)
	{
		long sum = accumulate(A.begin(), A.end(), 0L);
		long N = A.size(), value = 0;
		for (int i = 0; i < N; ++i)
			value += i * A[i];
		long res = value;
		for (int i = 1; i < N; ++i)
		{
			value = value + sum - N * A[N - i];
			res = max(res, value);
		}
		return res;
	}
};