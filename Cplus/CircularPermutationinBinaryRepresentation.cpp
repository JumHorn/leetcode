#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> circularPermutation(int n, int start)
	{
		int len = pow(2, n);
		vector<int> res(len);
		res[0] = start;
		int tmp = 0;
		while (start)
		{
			tmp ^= start;
			start >>= 1;
		}
		for (int i = 1; i < len; i++)
		{
			tmp++;
			if (tmp >= len)
				tmp -= len;
			res[i] = tmp ^ (tmp >> 1);
		}
		return res;
	}
};
