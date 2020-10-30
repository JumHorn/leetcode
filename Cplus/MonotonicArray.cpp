#include <vector>
using namespace std;

class Solution
{
public:
	bool isMonotonic(vector<int> &A)
	{
		int N = A.size(), i = 0;
		for (i = 1; i < N; ++i)
		{
			if (A[i - 1] > A[i])
				break;
		}
		if (i == N)
			return true;
		for (i = 1; i < N; ++i)
		{
			if (A[i - 1] < A[i])
				break;
		}
		return i == N;
	}
};