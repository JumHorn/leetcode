#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> constructRectangle(int area)
	{
		for (int i = sqrt(area); i >= 1; --i)
		{
			if (area % i == 0)
				return {area / i, i};
		}
		return {};
	}
};