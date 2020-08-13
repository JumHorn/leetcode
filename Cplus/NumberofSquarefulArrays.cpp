#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSquarefulPerms(vector<int> &A)
	{
		return dfs(A, 0);
	}

	int dfs(vector<int> &A, int index)
	{
		int N = A.size();
		if (index == N)
			return 1;
		int res = 0;
		unordered_set<int> seen;
		for (int i = index; i < N; i++)
		{
			if (index == 0 || isSquare(A[index - 1] + A[i]))
			{
				if (seen.find(A[i]) == seen.end())
				{
					seen.insert(A[i]);
					swap(A[index], A[i]);
					res += dfs(A, index + 1);
					swap(A[index], A[i]);
				}
			}
		}
		return res;
	}

	bool isSquare(int n)
	{
		int lo = 0, hi = n;
		while (lo < hi)
		{
			long mi = (hi - lo) / 2 + lo;
			if (mi * mi < n)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo * lo == n;
	}
};