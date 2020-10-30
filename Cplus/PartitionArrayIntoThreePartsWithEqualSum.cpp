#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canThreePartsEqualSum(vector<int> &A)
	{
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 3)
			return false;
		sum /= 3;

		int i = 0, part = A[0], N = A.size();
		while (++i < N && part != sum)
			part += A[i];
		if (i == N || part != sum)
			return false;
		part = A[i];
		while (++i < N && part != sum)
			part += A[i];
		return i != N && part == sum;
	}
};