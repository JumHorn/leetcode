#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
	{
		int N = original.size();
		if (m * n != N)
			return {};
		vector<vector<int>> res(m, vector<int>(n));
		for (int i = 0; i < N; ++i)
			res[i / n][i % n] = original[i];
		return res;
	}
};