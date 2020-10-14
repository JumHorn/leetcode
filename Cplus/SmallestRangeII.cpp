#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int smallestRangeII(vector<int> &A, int K)
	{
		sort(A.begin(), A.end());
		int N = A.size(), res = A[N - 1] - A[0];
		for (int i = 0; i < N - 1; ++i)
		{
			int a = A[i], b = A[i + 1];
			int high = max(A[N - 1] - K, a + K);
			int low = min(A[0] + K, b - K);
			res = min(res, high - low);
		}
		return res;
	}
};