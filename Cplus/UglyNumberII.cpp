#include <algorithm>
#include <vector>
using namespace std;

/*
(2) 1×2, 2×2, 3×2, 4×2, 5×2, …
(3) 1×3, 2×3, 3×3, 4×3, 5×3, …
(5) 1×5, 2×5, 3×5, 4×5, 5×5, …
*/

class Solution
{
public:
	int nthUglyNumber(int n)
	{
		vector<int> res(n);
		res[0] = 1;
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i < n; i++)
		{
			res[i] = min({res[i2] * 2, res[i3] * 3, res[i5] * 5});
			if (res[i] == res[i2] * 2)
				++i2;
			if (res[i] == res[i3] * 3)
				++i3;
			if (res[i] == res[i5] * 5)
				++i5;
		}
		return res.back();
	}
};