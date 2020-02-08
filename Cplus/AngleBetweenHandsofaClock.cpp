#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
	double angleClock(int hour, int minutes)
	{
		double anglehour = hour * 360 / 12 + minutes / 60.0 * 30, angleminutes = minutes * 360 / 60;
		double diff = abs(anglehour - angleminutes);
		return min(diff, 360 - diff);
	}
};
