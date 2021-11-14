#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
	{
		sort(tasks.begin(), tasks.end());
		sort(workers.begin(), workers.end(), greater<int>());
		int lo = 0, hi = min(workers.size(), tasks.size()) + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (check(tasks, workers, mi, pills, strength))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool check(vector<int> &tasks, vector<int> &workers, int index, int pills, int strength)
	{
		multiset<int> worker(workers.begin(), workers.begin() + index);
		for (int i = index - 1; i >= 0; --i)
		{
			auto it = --worker.end();
			if (tasks[i] > *it)
			{
				if (pills <= 0)
					return false;
				it = worker.lower_bound(tasks[i] - strength);
				if (it == worker.end())
					return false;
				--pills;
			}
			worker.erase(it);
		}
		return true;
	}
};