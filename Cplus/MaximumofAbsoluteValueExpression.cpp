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
		int n = arr1.size(), res = 0;
		//A+B
		for (int i = 1, index = 0; i < n; i++)
		{
			int tmp = arr1[i] - arr1[index] + arr2[i] - arr2[index] + i - index;
			res = max(res, tmp);

			if (arr1[i] + arr2[i] + 2 * i < arr1[index] + arr2[index] + 2 * index)
				index = i;
		}
		//A-B
		for (int i = 1, index = 0; i < n; i++)
		{
			int tmp = arr1[i] - arr1[index] - arr2[i] + arr2[index] + i - index;
			res = max(res, tmp);

			if (arr1[i] - arr2[i] + 2 * i < arr1[index] - arr2[index] + 2 * index)
				index = i;
		}
		//-A+B
		for (int i = 1, index = 0; i < n; i++)
		{
			int tmp = -arr1[i] + arr1[index] + arr2[i] - arr2[index] + i - index;
			res = max(res, tmp);

			if (-arr1[i] + arr2[i] + 2 * i < -arr1[index] + arr2[index] + 2 * index)
				index = i;
		}
		//-A-B
		for (int i = 1, index = 0; i < n; i++)
		{
			int tmp = -arr1[i] + arr1[index] - arr2[i] + arr2[index] + i - index;
			res = max(res, tmp);

			if (-arr1[i] - arr2[i] + 2 * i < -arr1[index] - arr2[index] + 2 * index)
				index = i;
		}
		return res;
	}
};