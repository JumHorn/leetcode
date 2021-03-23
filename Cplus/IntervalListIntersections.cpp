#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
	{
		vector<vector<int>> res;
		for (int i = 0, j = 0, N = A.size(), M = B.size(); i < N && j < M;)
		{
			if (A[i][0] <= B[j][1] && B[j][0] <= A[i][1])
				res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
			A[i][1] <= B[j][1] ? ++i : ++j;
		}
		return res;
	}
};