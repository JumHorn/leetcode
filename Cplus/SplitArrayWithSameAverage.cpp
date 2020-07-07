#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
	bool backTracking(vector<int> &A, int index, int count, int subsum, int sum)
	{
		int n = A.size();
		if (index >= n)
			return false;
		if (count != 0 && subsum * n == sum * count)
			return true;
		if (sum * count % n != 0)
			return false;
		if (subsum * n > sum * count)
			return false;
		if (backTracking(A, index + 1, count, subsum, sum))
			return true;
		if (backTracking(A, index + 1, count + 1, subsum + A[index], sum))
			return true;
		return false;
	}

	bool isPossible(vector<int> &A, int sum)
	{
		int n = A.size();
		for (int i = 1; i <= n / 2; i++)
		{
			if (sum * i % n == 0)
				return true;
		}
		return false;
	}

	bool splitArraySameAverage(vector<int> &A)
	{
		int n = A.size();
		sort(A.begin(), A.end());
		int sum = accumulate(A.begin(), A.end(), 0);
		// early pruning
		if (!isPossible(A, sum))
			return false;
		return backTracking(A, 0, 0, 0, sum);
	}
};