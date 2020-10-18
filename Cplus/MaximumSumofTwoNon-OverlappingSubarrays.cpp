#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
	{
		return max(sumTwoWindow(A, L, M), sumTwoWindow(A, M, L));
	}

	int sumTwoWindow(vector<int> &A, int L, int M)
	{
		int N = A.size();
		int windowL = accumulate(A.begin(), A.begin() + L, 0);
		int windowM = accumulate(A.begin() + L, A.begin() + L + M, 0);
		int maxL = windowL;
		int res = windowL + windowM;
		for (int i = L + M, j = L; i < N; ++i, ++j)
		{
			windowL = windowL - A[j - L] + A[j];
			windowM = windowM - A[i - M] + A[i];
			maxL = max(maxL, windowL);
			res = max(res, maxL + windowM);
		}
		return res;
	}
};