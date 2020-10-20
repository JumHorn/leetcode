#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> pathInZigZagTree(int label)
	{
		int height = 0;
		while ((1 << height) <= label)
			++height;
		vector<int> res(height);
		for (; label >= 1; label /= 2)
		{
			res[--height] = label;
			label = (1 << (height + 1)) - 1 - label + (1 << height);
		}
		return res;
	}
};