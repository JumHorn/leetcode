#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int leastInterval(vector<char> &tasks, int n)
	{
		vector<int> hash(26);
		for (auto c : tasks)
			++hash[c - 'A'];
		sort(hash.begin(), hash.end(), greater<int>()); //des
		int maxCount = hash[0], maxSameCount = 1;
		for (int i = 1; i < 26 && hash[i] == hash[0]; ++i)
			++maxSameCount;
		return max((int)tasks.size(), (maxCount - 1) * (n + 1) + maxSameCount);
	}
};