#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
	{
		int m = tomatoSlices, n = cheeseSlices;
		if (m < 2 * n || (m - 2 * n) % 2 != 0 || 4 * n - m < 0)
			return vector<int>();
		return {(m - 2 * n) / 2, n - (m - 2 * n) / 2};
	}
};
