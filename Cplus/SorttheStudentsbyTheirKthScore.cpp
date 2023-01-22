#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
	{
		sort(score.begin(), score.end(), [&](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[k] > rhs[k]; });
		return score;
	}
};