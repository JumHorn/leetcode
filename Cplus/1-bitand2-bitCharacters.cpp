#include <vector>
using namespace std;

class Solution
{
public:
	bool isOneBitCharacter(vector<int> &bits)
	{
		int N = bits.size();
		if (N == 0)
			return false;
		if (N == 1 || bits[N - 1] == 1)
			return bits[0] == 0;
		int one = 0;
		for (int i = N - 2; i >= 0 && bits[i] == 1; --i)
			++one;
		return one % 2 == 0;
	}
};