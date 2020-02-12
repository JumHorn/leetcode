#include <vector>
using namespace std;

class Solution
{
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B)
	{
		int n = A.size();
		vector<unsigned int> AA(n), BB(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[i][j] == 1)
					AA[i] |= 1 << j;
				if (B[i][j] == 1)
					BB[i] |= 1 << j;
			}
		}

		int res = 0;
		for (int i = -(n - 1); i <= (n - 1); i++)
			for (int j = -(n - 1); j <= (n - 1); j++)
			{
				vector<unsigned int> tmp(translate(AA, i, j));
				res = max(res, overlapCount(tmp, BB));
			}
		return res;
	}

	vector<unsigned int> translate(vector<unsigned int>& v, int i, int j)
	{
		vector<unsigned int> res(v);
		static int mask[] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823};
		int n = v.size();
		if (i >= 0)
		{
			for (int k = 0; k < n; k++)
				res[k] >>= i;
		}
		else
		{
			i = -i;
			for (int k = 0; k < n; k++)
				res[k] = ((res[k] << i) & mask[n]);
		}

		if (j >= 0)
		{
			for (int k = n - j - 1; k >= 0; k--)
				res[k + j] = res[k];
			for (int k = 0; k < j; k++)
				res[k] = 0;
		}
		else
		{
			j = -j;
			for (int k = j; k < n; k++)
				res[k - j] = res[k];
			for (int k = n - j; k < n; k++)
				res[k] = 0;
		}
		return res;
	}

	int overlapCount(vector<unsigned int>& AA, vector<unsigned int>& BB)
	{
		int res = 0;
		for (int i = 0; i < (int)AA.size(); i++)
			res += bitCount(AA[i] & BB[i]);
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			n &= n - 1;
			res++;
		}
		return res;
	}
};
