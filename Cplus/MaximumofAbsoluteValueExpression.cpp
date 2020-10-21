#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
/*
abs(A) + abs(B) = max(A+B, A-B, -A+B, -A-B)
*/

class Solution
{
public:
	int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
	{
		int res = 0, N = arr1.size();
		vector<int> coeff = {1, -1};
		for (int p : coeff)
		{
			for (int q : coeff)
			{
				int smallest = p * arr1[0] + q * arr2[0] + 0;
				for (int i = 1; i < N; ++i)
				{
					int cur = p * arr1[i] + q * arr2[i] + i;
					res = max(res, cur - smallest);
					smallest = min(smallest, cur);
				}
			}
		}
		return res;
	}
};