#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minIncrementForUnique(vector<int> &A)
	{
		sort(A.begin(), A.end());
		int res = 0, N = A.size();
		for (int i = 1; i < N; ++i)
		{
			if (A[i] <= A[i - 1])
			{
				res += A[i - 1] + 1 - A[i];
				A[i] = A[i - 1] + 1;
			}
		}
		return res;
	}
};