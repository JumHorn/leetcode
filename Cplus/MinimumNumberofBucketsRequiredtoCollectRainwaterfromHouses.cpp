#include <climits>
#include <string>
using namespace std;

class Solution
{
public:
	int minimumBuckets(string street)
	{
		const int INF = INT_MIN;
		int res = 0, h = 0, b = INF, N = street.length();
		for (int i = 0; i < N; ++i)
		{
			if (street[i] == 'H')
			{
				if (b == i - 1)
					b = INF;
				else
				{
					if (i < N - 1 && street[i + 1] == '.') //add to right
						b = i + 1;
					else if (i > 0 && street[i - 1] == '.') //add to left
						b = i - 1;
					else
						return -1;
					++res;
				}
			}
		}
		return res;
	}
};