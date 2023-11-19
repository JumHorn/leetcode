#include <string>
using namespace std;

class Solution
{
public:
	int findMinimumOperations(string s1, string s2, string s3)
	{
		int res = min(samePrefix(s1, s2), samePrefix(s2, s3));
		if (res == 0)
			return -1;
		return s1.size() + s2.size() + s3.size() - 3 * res;
	}

	int samePrefix(string &s1, string &s2)
	{
		int res = 0, N1 = s1.size(), N2 = s2.size();
		for (; res < N1 && res < N2; ++res)
		{
			if (s1[res] != s2[res])
				break;
		}
		return res;
	}
};