#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int primePalindrome(int N)
	{
		for (int len = 1;; ++len)
		{
			int x = pow(10, (len - 1) / 2), y = pow(10, (len + 1) / 2);
			for (int i = x; i < y; ++i)
			{
				long long val = i;
				for (int j = len % 2 == 1 ? i / 10 : i; j > 0; j /= 10)
					val = val * 10 + j % 10;
				if (val >= N && isPrimer(val))
					return val;
			}
		}
		return 0;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (int i = 2; i * i <= N; ++i)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
};