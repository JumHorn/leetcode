#include <vector>
using namespace std;

/*
// another gray code to decimal always used

int grayCodeToDecimal(int n)
{
	int res = 0;
	for (; n != 0; n >>= 1)
		res ^= n;
	return res;
}
*/

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> res(1 << n);
		for (int i = 0; i < (1 << n); ++i)
			res[i] = i ^ (i >> 1);
		return res;
	}
};