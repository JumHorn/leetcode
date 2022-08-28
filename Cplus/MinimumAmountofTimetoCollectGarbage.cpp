#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int garbageCollection(vector<string> &garbage, vector<int> &travel)
	{
		const string mpg = "MPG";
		int res = 0, N = garbage.size();
		for (auto c : mpg)
		{
			int t = 0;
			for (int i = 0; i < N; ++i)
			{
				int cnt = count(garbage[i].begin(), garbage[i].end(), c);
				if (cnt > 0)
				{
					res += t + cnt;
					t = 0;
				}
				if (i < N - 1)
					t += travel[i];
			}
		}
		return res;
	}
};