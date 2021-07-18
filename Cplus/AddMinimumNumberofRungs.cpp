#include <vector>
using namespace std;

class Solution
{
public:
	int addRungs(vector<int> &rungs, int dist)
	{
		int N = rungs.size(), res = 0, pre = 0;
		for (int i = 0; i < N; ++i)
		{
			res += (rungs[i] - pre - 1) / dist;
			pre = rungs[i];
		}
		return res;
	}
};