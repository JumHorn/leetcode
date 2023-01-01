#include <string>
using namespace std;

class Solution
{
public:
	int minimumPartition(string s, int k)
	{
		int N = s.size(), res = 0;
		for (int i = N - 1; i >= 0;)
		{
			long long j = i, val = 0;
			for (long long base = 1; val <= k && j >= 0; base *= 10, --j)
				val += (s[j] - '0') * base;
			++res;
			if (j == -1 && val <= k)
				break;
			if (i == j + 1)
				return -1;
			i = j + 1;
		}
		return res;
	}
};