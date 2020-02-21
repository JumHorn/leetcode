#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> prevPermOpt1(vector<int> &A)
	{
		for (int i = A.size() - 1; i > 0; --i)
		{
			if (A[i] < A[i - 1])
			{
				int lo = i - 1, hi = A.size() - 1;
				if (A[hi] < A[i - 1])
				{
					if (A[hi] == A[i])
						swap(A[i - 1], A[i]);
					else
						swap(A[i - 1], A[hi]);
				}
				else
				{
					while (lo < hi)
					{
						int mi = (hi - lo) / 2 + lo;
						if (A[mi] < A[i - 1])
							lo = mi + 1;
						else
							hi = mi;
					}
					if (A[lo - 1] == A[i])
						swap(A[i - 1], A[i]);
					else
						swap(A[i - 1], A[lo - 1]);
				}
				break;
			}
		}
		return A;
	}
};
