#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestPerimeter(vector<int> &A)
	{
		int N = A.size();
		if (N < 3)
			return 0;
		make_heap(A.begin(), A.end());
		pop_heap(A.begin(), A.end());
		pop_heap(A.begin(), A.end() - 1);
		for (int i = N - 1; i >= 2; --i)
		{
			pop_heap(A.begin(), A.begin() + i - 1);
			if (A[i] < A[i - 1] + A[i - 2])
				return A[i] + A[i - 1] + A[i - 2];
		}
		return 0;
	}
};