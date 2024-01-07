#include <cmath>
using namespace std;

class Solution
{
public:
	int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
	{
		int res = 2;
		if (a == e || b == f)
		{
			if (a == e && c == a)
			{
				if (!((d >= b && d <= f) || (d <= b && d >= f)))
					return 1;
			}
			else if (b == f && d == b)
			{
				if (!((c >= a && c <= e) || (c >= e && c <= a)))
					return 1;
			}
			else
				res = 1;
		}
		if (abs(f - d) == abs(c - e))
		{
			res = 1;
			if (abs(f - b) == abs(a - e))
			{
				if ((a - e) * (d - f) == (c - e) * (b - f))
				{
					if ((b >= d && b <= f) || (b >= f && b <= d))
					{
						if (a >= c && a <= e || a >= e && a <= c)
							return 2;
					}
				}
			}
		}
		return res;
	}
};