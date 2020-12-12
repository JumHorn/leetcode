#include <vector>
using namespace std;

class Solution
{
public:
	int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
	{
		int N = boxes.size(), res = 0;
		for (int i = 0, j = 0; i < N; i = j)
		{
			int weight = 0, preport = -1;
			for (j = i; j < N && j - i + 1 <= maxBoxes && weight + boxes[j][1] <= maxWeight; ++j)
			{
				weight += boxes[j][1];
				if (preport != boxes[j][0])
				{
					++res;
					preport = boxes[j][0];
				}
			}
			++res;
		}
		return res;
	}
};