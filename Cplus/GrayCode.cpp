#include <vector>
using namespace std;

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