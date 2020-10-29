#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDeletionSize(vector<string> &A)
	{
		int res = 0, M = A.size(), N = A[0].length();
		for (int i = 0, j = 0; j < N; ++j)
		{
			for (i = 1; i < M; ++i)
			{
				if (A[i - 1][j] > A[i][j])
					break;
			}
			if (i != M)
				++res;
		}
		return res;
	}
};