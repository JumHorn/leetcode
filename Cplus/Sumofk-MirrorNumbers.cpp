#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long kMirror(int k, int n)
	{
		long long res = 0;
		for (int len = 1; n > 0; ++len)
		{
			int x = pow(10, (len - 1) / 2), y = pow(10, (len + 1) / 2);
			for (int i = x; i < y; ++i)
			{
				long long val = i;
				for (int j = len % 2 == 1 ? i / 10 : i; j > 0; j /= 10)
					val = val * 10 + j % 10;
				if (checkKMirror(k, val))
				{
					res += val;
					if (--n == 0)
						break;
				}
			}
		}
		return res;
	}

	bool checkKMirror(int k, long long n)
	{
		long long val = n, mirrorval = 0;
		for (; val > 0; val /= k)
			mirrorval = (val % k) + mirrorval * k;
		return n == mirrorval;
	}
};