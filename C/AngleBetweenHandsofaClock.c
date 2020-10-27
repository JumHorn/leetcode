#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

double angleClock(int hour, int minutes)
{
	double anglehour = hour * 360 / 12 + minutes / 60.0 * 30, angleminutes = minutes * 360 / 60;
	double diff = fabs(anglehour - angleminutes);
	return min(diff, 360 - diff);
}
