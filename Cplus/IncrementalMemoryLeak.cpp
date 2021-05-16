#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> memLeak(int memory1, int memory2)
	{
		int c = 1;
		for (; c <= memory1 || c <= memory2; ++c)
		{
			if (memory1 >= memory2)
				memory1 -= c;
			else
				memory2 -= c;
		}
		return {c, memory1, memory2};
	}
};