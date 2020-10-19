#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> prevPermOpt1(vector<int> &A)
	{
		int N = A.size();
		for (int i = N - 1; i > 0; --i)
		{
			if (A[i] < A[i - 1])
			{
				int lo = i, hi = N;
				while (lo < hi)
				{
					int mi = (hi - lo) / 2 + lo;
					if (A[mi] < A[i - 1])
						lo = mi + 1;
					else
						hi = mi;
				}
				swap(A[i - 1], A[lo - 1]);
				break;
			}
		}
		return A;
	}
};