#include <vector>
using namespace std;

class Solution
{
public:
	int numEquivDominoPairs(vector<vector<int>> &dominoes)
	{
		vector<vector<int>> count(10, vector<int>(10));
		for (auto &domino : dominoes)
		{
			if (domino[0] <= domino[1])
				++count[domino[0]][domino[1]];
			else
				++count[domino[1]][domino[0]];
		}
		int res = 0;
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = i; j <= 9; ++j)
				res += count[i][j] * (count[i][j] - 1) / 2;
		}
		return res;
	}
};