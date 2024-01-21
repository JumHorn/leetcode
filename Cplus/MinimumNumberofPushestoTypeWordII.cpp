#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumPushes(string word)
	{
		vector<int> count(26);
		for (auto c : word)
			++count[c - 'a'];
		sort(count.begin(), count.end(), greater<int>());
		int key = 0, res = 0;
		for (auto n : count)
		{
			if (n > 0)
			{
				++key;
				res += (key + 7) / 8 * n;
			}
		}
		return res;
	}
};