#include <vector>
using namespace std;

class Solution
{
public:
	int smallestRangeI(vector<int> &A, int K)
	{
		int max = A[0], min = A[0];
		for (auto n : A)
		{
			if (n > max)
				max = n;
			else if (n < min)
				min = n;
		}
		int res = max - min - K * 2;
		return res < 0 ? 0 : res;
	}
};