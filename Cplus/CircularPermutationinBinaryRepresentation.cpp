#include <vector>
using namespace std;

/*
gray code
*/

class Solution
{
public:
	vector<int> circularPermutation(int n, int start)
	{
		vector<int> res(1 << n);
		for (int i = 0; i < (1 << n); ++i)
			res[i] = start ^ i ^ (i >> 1);
		return res;
	}
};