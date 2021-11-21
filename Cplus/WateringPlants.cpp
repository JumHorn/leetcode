#include <vector>
using namespace std;

class Solution
{
public:
	int wateringPlants(vector<int> &plants, int capacity)
	{
		int res = 0, N = plants.size(), c = capacity;
		for (int i = 0; i < N; ++i)
		{
			if (c < plants[i])
			{
				res += i * 2 + 1;
				c = capacity - plants[i];
			}
			else
			{
				res += 1;
				c -= plants[i];
			}
		}
		return res;
	}
};