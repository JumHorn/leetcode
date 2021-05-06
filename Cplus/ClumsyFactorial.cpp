#include <algorithm>
using namespace std;

class Solution
{
public:
	int clumsy(int N)
	{
		int res = N * max(N - 1, 1) / max(N - 2, 1);
		N -= 3;
		for (; N > 0; N -= 4)
		{
			res += N;
			res -= (N - 1) * max(N - 2, 1) / max(N - 3, 1);
		}
		return res;
	}
};