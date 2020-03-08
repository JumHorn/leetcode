#include <vector>
using namespace std;

class Solution
{
public:
	int numTimesAllBlue(vector<int>& light)
	{
		int n = light.size();
		vector<int> bulb(n + 1);
		int res = 0, blue = 0, on = 0;
		for (int i = 0; i < n; i++)
		{
			bulb[light[i]] = 1;
			on++;
			if (light[i] - blue == 1)
			{
				blue++;
				while (blue + 1 <= n && bulb[blue + 1] == 1)
					blue++;
				if (blue == on)
					res++;
			}
		}
		return res;
	}
};
