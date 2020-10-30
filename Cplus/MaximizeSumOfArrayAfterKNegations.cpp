#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestSumAfterKNegations(vector<int> &A, int K)
	{
		int N = A.size();
		sort(A.begin(), A.end());
		for (int i = 0; i < N && A[i] < 0 && K > 0; ++i, --K)
			A[i] = -A[i];
		K %= 2;
		int sum = accumulate(A.begin(), A.end(), 0);
		int minimum = *min_element(A.begin(), A.end());
		return sum - (K == 0 ? 0 : 2 * minimum);
	}
};