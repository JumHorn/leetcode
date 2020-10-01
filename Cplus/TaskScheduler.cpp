#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

/*
greedily schedule the most count task first
*/

class Solution
{
public:
	int leastInterval(vector<char> &tasks, int n)
	{
		vector<int> hash(26);
		for (auto c : tasks)
			++hash[c - 'A'];
		sort(hash.begin(), hash.end(), greater<int>());
		int res = 0, minTask, i;
		while (hash[0] > 0)
		{
			minTask = hash[0];
			for (i = 0; i < min(n + 1, 26) && hash[i] > 0; ++i)
				minTask = min(minTask, hash[i]);
			if (i < 26 && hash[i] != 0)
				minTask = minTask - hash[i] + 1;
			for (i = 0; i < min(n + 1, 26) && hash[i] > 0; ++i)
				hash[i] -= minTask;
			res += (n + 1) * minTask;
			sort(hash.begin(), hash.end(), greater<int>());
		}
		res -= n + 1 - i;
		return res;
	}
};