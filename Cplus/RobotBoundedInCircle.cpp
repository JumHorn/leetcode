#include <string>
using namespace std;

class Solution
{
public:
	bool isRobotBounded(string instructions)
	{
		int direction[4] = {0}, d = 0;
		for (int i = 0; i < 4; i++)
		{
			for (auto n : instructions)
			{
				if (n == 'G')
					direction[d]++;
				else if (n == 'L')
					d = (d - 1 + 4) % 4;
				else
					d = (d + 1) % 4;
			}
		}
		return direction[0] == direction[2] && direction[1] == direction[3];
	}
};

