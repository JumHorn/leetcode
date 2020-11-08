#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDeletions(string s)
	{
		vector<int> count(26);
		for (auto c : s)
			++count[c - 'a'];
		sort(count.begin(), count.end());
		int res = 0;
		for (int i = 26 - 2; i >= 0 && count[i] > 0; --i)
		{
			if (count[i] >= count[i + 1])
			{
				res += count[i] - max(count[i + 1] - 1, 0);
				count[i] = count[i + 1] - 1;
			}
		}
		return res;
	}
};