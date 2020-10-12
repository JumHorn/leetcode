#include <vector>
using namespace std;

class Solution
{
public:
	int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
	{
		int n = img1.size();
		vector<unsigned int> A(n), B(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (img1[i][j] == 1)
					A[i] |= 1 << j;
				if (img2[i][j] == 1)
					B[i] |= 1 << j;
			}
		}

		int res = 0;
		for (int i = -(n - 1); i <= (n - 1); ++i)
		{
			for (int j = -(n - 1); j <= (n - 1); ++j)
			{
				vector<unsigned int> AA = translate(A, i, j);
				res = max(res, overlapCount(AA, B));
			}
		}
		return res;
	}

	vector<unsigned int> translate(vector<unsigned int> &v, int i, int j)
	{
		vector<unsigned int> res(v);
		int mask[32];
		for (int k = 0; k < 32; ++k)
			mask[k] = (1u << k) - 1;
		int n = v.size();
		if (i >= 0)
		{
			for (int k = 0; k < n; ++k)
				res[k] >>= i;
		}
		else
		{
			i = -i;
			for (int k = 0; k < n; ++k)
				res[k] = ((res[k] << i) & mask[n]);
		}

		if (j >= 0)
		{
			for (int k = n - j - 1; k >= 0; --k)
				res[k + j] = res[k];
			for (int k = 0; k < j; ++k)
				res[k] = 0;
		}
		else
		{
			j = -j;
			for (int k = j; k < n; ++k)
				res[k - j] = res[k];
			for (int k = n - j; k < n; ++k)
				res[k] = 0;
		}
		return res;
	}

	int overlapCount(vector<unsigned int> &AA, vector<unsigned int> &BB)
	{
		int res = 0;
		for (int i = 0; i < (int)AA.size(); ++i)
			res += bitCount(AA[i] & BB[i]);
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			n &= n - 1;
			++res;
		}
		return res;
	}
};