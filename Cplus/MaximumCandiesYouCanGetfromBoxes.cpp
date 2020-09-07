#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
	{
		queue<int> open;
		for (auto n : initialBoxes)
		{
			if (status[n] == 0) //0 means we cannot seen this closed box
				status[n] = 3;  //3 means we have this closed box in hand
			else
				open.push(n); //we get this open box
		}
		int res = 0;
		while (!open.empty())
		{
			int n = open.front();
			open.pop();
			if (status[n] == -1) //-1 means already take all candies
				continue;
			status[n] = -1;
			res += candies[n];

			for (auto k : keys[n])
			{
				if (status[k] == -1)
					continue;
				if (status[k] == 3)
					open.push(k);
				else
					status[k] = 2; //2 means we have this box's key
			}
			for (auto b : containedBoxes[n])
			{
				if (status[b] == -1)
					continue;
				if (status[b] >= 1)
					open.push(b);
				else
					status[b] = 3;
			}
		}
		return res;
	}
};