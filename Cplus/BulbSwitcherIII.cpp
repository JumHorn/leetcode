#include <vector>
using namespace std;

class Solution
{
public:
	int numTimesAllBlue(vector<int> &light)
	{
		int res = 0, bulbid = 0;
		for (int i = 0; i < (int)light.size(); ++i)
		{
			bulbid = max(bulbid, light[i]);
			if (bulbid == i + 1)
				++res;
		}
		return res;
	}
};