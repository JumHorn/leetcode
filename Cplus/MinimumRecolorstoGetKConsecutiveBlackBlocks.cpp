#include <string>
using namespace std;

class Solution
{
public:
	int minimumRecolors(string blocks, int k)
	{
		int op = 0, N = blocks.size();
		for (int i = 0; i < k; ++i)
		{
			if (blocks[i] == 'W')
				++op;
		}
		int res = op;
		for (int i = k; i < N; ++i)
		{
			if (blocks[i] == 'W')
				++op;
			if (blocks[i - k] == 'W')
				--op;
			res = min(res, op);
		}
		return res;
	}
};