#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X)
	{
		int satisfied = 0, n = customers.size();
		for (int i = 0; i < n; i++)
			if (grumpy[i] == 0)
				satisfied += customers[i];
		int res = 0;
		for (int i = 0, j = 0; i < n; i++)
		{
			if (i - j + 1 > X)
			{
				if (grumpy[j] == 1)
					satisfied -= customers[j];
				j++;
			}
			if (grumpy[i] == 1)
				satisfied += customers[i];
			res = max(res, satisfied);
		}
		return res;
	}
};
