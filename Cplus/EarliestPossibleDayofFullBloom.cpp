#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
	{
		int N = plantTime.size(), res = 0;
		vector<pair<int, int>> v; //{grow,plan}
		for (int i = 0; i < N; ++i)
			v.push_back({growTime[i], plantTime[i]});
		sort(v.begin(), v.end());
		for (auto &[g, p] : v)
		{
			res = max(res, g);
			res += p;
		}
		return res;
	}
};