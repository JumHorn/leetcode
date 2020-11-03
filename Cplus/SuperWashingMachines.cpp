#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMinMoves(vector<int> &machines)
	{
		int N = machines.size();
		int sum = accumulate(machines.begin(), machines.end(), 0);
		if (sum % N != 0)
			return -1;
		int avg = sum / N, res = 0, count = 0;
		for (int i = 0; i < (int)machines.size(); ++i)
			machines[i] -= avg;
		for (int i = 0; i < (int)machines.size(); ++i)
		{
			count += machines[i];
			res = max(res, max(machines[i], abs(count)));
		}
		return res;
	}
};