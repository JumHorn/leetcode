#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
	{
		int N = grid.size();
		vector<int> count(N * N + 1);
		for (auto &v : grid)
		{
			for (auto n : v)
				++count[n];
		}
		int a = 0, b = 0;
		for (int i = 1; i <= N * N; ++i)
		{
			if (count[i] == 2)
				a = i;
			else if (count[i] == 0)
				b = i;
		}
		return {a, b};
	}
};