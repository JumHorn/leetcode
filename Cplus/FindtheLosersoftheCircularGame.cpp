#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> circularGameLosers(int n, int k)
	{
		vector<int> f(n);
		for (int i = 0, j = k; f[i] == 0; i = (i + j) % n, j += k)
			f[i] = 1;
		vector<int> res;
		for (int i = 0; i < n; ++i)
		{
			if (f[i] == 0)
				res.push_back(i + 1);
		}
		return res;
	}
};