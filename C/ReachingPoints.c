#include <stdbool.h>

bool reachingPoints(int sx, int sy, int tx, int ty)
{
	if (tx < sx || ty < sy)
		return false;
	if ((tx == sx && ty % tx == sy % tx) || (ty == sy && tx % ty == sx % ty))
		return true;
	if (tx > ty)
		return reachingPoints(sx, sy, tx % ty, ty);
	return reachingPoints(sx, sy, tx, ty % tx);
}
