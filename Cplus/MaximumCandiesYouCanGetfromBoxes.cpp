#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes)
	{
		unordered_set<int> open;
		for (auto n : initialBoxes)
		{
			if (status[n] == 0)
				status[n] = 3;	//closed box in hand
			else
				open.insert(n);
		}
		int res = 0;
		while (!open.empty())
		{
			int n = *open.begin();
			open.erase(n);
			if (status[n] == -1)
				continue;
			status[n] = -1;
			res += candies[n];

			for (auto k : keys[n])
			{
				if (status[k] > 1)
					open.insert(k);
				else
					status[k] = 2;
			}
			for (auto b : containedBoxes[n])
			{
				if (status[b] >= 1)
					open.insert(b);
				else
					status[b] = 3;
			}
		}
		return res;
	}
};
