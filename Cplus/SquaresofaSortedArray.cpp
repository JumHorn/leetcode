#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortedSquares(vector<int> &A)
	{
		int N = A.size();
		vector<int> res(N);
		int i = lower_bound(A.begin(), A.end(), 0) - A.begin(), j = i - 1;
		//merge
		for (int k = 0; i < N || j >= 0; ++k)
		{
			if (i == N)
				res[k] = A[j] * A[j--];
			else if (j == -1)
				res[k] = A[i] * A[i++];
			else
				res[k] = (A[i] * A[i] > A[j] * A[j]) ? A[j] * A[j--] : A[i] * A[i++];
		}
		return res;
	}
};