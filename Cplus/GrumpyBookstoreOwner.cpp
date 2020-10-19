#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X)
	{
		int satisfied = 0, N = customers.size();
		for (int i = 0; i < N; ++i)
		{
			if (grumpy[i] == 0)
				satisfied += customers[i];
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (i >= X)
			{
				if (grumpy[i - X] == 1)
					satisfied -= customers[i - X];
			}
			if (grumpy[i] == 1)
				satisfied += customers[i];
			res = max(res, satisfied);
		}
		return res;
	}
};