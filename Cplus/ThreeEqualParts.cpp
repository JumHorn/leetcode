#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> threeEqualParts(vector<int> &A)
	{
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 3 != 0)
			return {-1, -1};
		sum /= 3;
		if (sum == 0)
			return {0, 2};
		int i = 0, j = 0, k = 0, ones = 0;
		while (A[k] != 1)
			++k;
		i = k;
		ones = 0;
		while (ones != sum)
		{
			if (A[++k] == 1)
				++ones;
		}
		j = k;
		ones = 0;
		while (ones != sum)
		{
			if (A[++k] == 1)
				++ones;
		}
		while (k < (int)A.size())
		{
			if (A[i] != A[j] || A[i] != A[k])
				return {-1, -1};
			++i;
			++j;
			++k;
		}
		return {i - 1, j};
	}
};