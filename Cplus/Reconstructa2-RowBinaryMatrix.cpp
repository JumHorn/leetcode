#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
	{
		vector<vector<int>> res(2, vector<int>(colsum.size()));
		for (auto i = 0; i < (int)colsum.size(); ++i)
		{
			res[0][i] = colsum[i] == 2 || (colsum[i] == 1 && lower < upper);
			res[1][i] = colsum[i] == 2 || (colsum[i] == 1 && !res[0][i]);
			upper -= res[0][i];
			lower -= res[1][i];
		}
		return upper == 0 && lower == 0 ? res : vector<vector<int>>();
	}
};