#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
	{
		int res = 0, n = A.size();
		if (L > M)
			swap(L, M);
		vector<int> window(n - L + 1);
		window[0] = accumulate(A.begin(), A.begin() + L, 0);
		for (int i = 1; i <= n - L; i++)
			window[i] = window[i - 1] - A[i - 1] + A[i + L - 1];
		int left = 0, right = *max_element(window.begin() + M, window.end());
		int m = accumulate(A.begin(), A.begin() + M, 0);
		res = right + m;
		for (int i = M; i < n; i++)
		{
			if (i - M - L >= 0)
				left = max(left, window[i - M - L]);
			if (i + L < n)
			{
				if (right == window[i])
					right = *max_element(window.begin() + i + 1, window.end());
			}
			else
				right = 0;
			m = m - A[i - M] + A[i];
			res = max(res, m + max(left, right));
		}
		return res;
	}
};