#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
	string longestDiverseString(int a, int b, int c)
	{
		return greedy(a, b, c, 'a', 'b', 'c');
	}

	string greedy(int a, int b, int c, char aa, char bb, char cc)
	{
		if (a < b)
			return greedy(b, a, c, bb, aa, cc);
		if (b < c)
			return greedy(a, c, b, aa, cc, bb);
		if (b == 0)
			return string(min(2, a), aa);
		int use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0;
		return string(use_a, aa) + string(use_b, bb) +
			   greedy(a - use_a, b - use_b, c, aa, bb, cc);
	}
};