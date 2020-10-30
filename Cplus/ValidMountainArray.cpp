#include <vector>
using namespace std;

class Solution
{
public:
	bool validMountainArray(vector<int> &A)
	{
		int N = A.size();
		if (N < 3)
			return false;
		int i = 1;
		while (i < N && A[i - 1] < A[i])
			++i;
		if (i == 1 || i == N)
			return false;
		while (i < N && A[i - 1] > A[i])
			++i;
		return i == N;
	}
};