#include <vector>
using namespace std;

class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int N = gas.size(), minus = 0, leftgas = 0, res = 0;
		for (int i = 0; i < N; ++i)
		{
			leftgas += gas[i] - cost[i];
			if (leftgas < 0)
			{
				res = i + 1;
				minus += leftgas;
				leftgas = 0;
			}
		}
		return minus + leftgas < 0 ? -1 : res;
	}
};