#include <vector>
using namespace std;

class Solution
{
public:
	int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
	{
		int res = 0, N = plants.size(), A = capacityA, B = capacityB;
		for (int i = 0, j = N - 1; i <= j; ++i, --j)
		{
			if (i == j)
				res += max(A, B) >= plants[i] ? 0 : 1;
			else
			{
				if (A < plants[i])
				{
					A = capacityA - plants[i];
					++res;
				}
				else
					A -= plants[i];

				if (B < plants[j])
				{
					B = capacityB - plants[j];
					++res;
				}
				else
					B -= plants[j];
			}
		}
		return res;
	}
};