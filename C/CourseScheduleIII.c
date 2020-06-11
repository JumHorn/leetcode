#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return (*(int **)lhs)[1] - (*(int **)rhs)[1];
}

int memdp(int **courses, int coursesSize, int index, int time, int (*dp)[10001])
{
	if (index >= coursesSize)
		return 0;
	if (dp[time][index] != -1)
		return dp[time][index];
	int res = 0;
	if (courses[index][0] + time <= courses[index][1])
	{
		int tmp = 1 + memdp(courses, coursesSize, index + 1, time + courses[index][0], dp);
		res = max(res, tmp);
	}
	int tmp = memdp(courses, coursesSize, index + 1, time, dp);
	return dp[time][index] = max(res, tmp);
}

int scheduleCourse(int **courses, int coursesSize, int *coursesColSize)
{
	qsort(courses, coursesSize, sizeof(int *), cmp);
	static int dp[10001][10001];
	memset(dp, -1, sizeof(dp));
	return memdp(courses, coursesSize, 0, 0, dp);
}