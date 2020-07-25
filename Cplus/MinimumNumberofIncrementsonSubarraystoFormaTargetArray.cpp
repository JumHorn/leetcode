#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberOperations(vector<int> &target)
	{
		int res = 0, pre = 0;
		for (auto n : target)
		{
			res += max(n - pre, 0);
			pre = n;
		}
		return res;
	}
};
