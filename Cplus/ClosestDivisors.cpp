#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> closestDivisors(int num)
	{
		int n = sqrt(num + 2), a = 0, b = 0, tmp;
		for (int i = n; i >= 1; i--)
		{
			if ((num + 1) % i == 0)
			{
				tmp = (num + 1) / i;
			}
			else if ((num + 2) % i == 0)
			{
				tmp = (num + 2) / i;
			}
			else
				continue;
			a = i;
			b = tmp;
			return {a, b};
		}
		return {a, b};
	}
};
