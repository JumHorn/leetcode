#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int equalSubstring(string s, string t, int maxCost)
	{
		int N = s.length();
		vector<int> diff(N);
		for (int i = 0; i < N; ++i)
			diff[i] = abs(s[i] - t[i]);
		int i = 0, j = 0, cost = 0;
		for (; j < N; ++j)
		{
			cost += diff[j];
			if (cost > maxCost)
				cost -= diff[i++];
		}
		return j - i;
	}
};