#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

int timeToZero(char *time)
{
	int hour, minute;
	sscanf(time, "%d:%d", &hour, &minute);
	return hour * 60 + minute;
}

int timeDiff(char *t0, char *t1)
{
	return timeToZero(t1) - timeToZero(t0);
}

int findMinDifference(char **timePoints, int timePointsSize)
{
	qsort(timePoints, timePointsSize, sizeof(char *), cmp);
	int res = INT_MAX, diff;
	for (int i = 1; i < timePointsSize; ++i)
	{
		diff = timeDiff(timePoints[i - 1], timePoints[i]);
		res = min(res, diff);
	}
	diff = timeDiff(timePoints[timePointsSize - 1], timePoints[0]);
	res = min(res, 1440 + diff);
	return res;
}
