#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestMountain(vector<int> &A)
	{
		int res = 0, peek, N = A.size();
		for (int i = 1, j = 0; i < N; j = i - 1)
		{
			while (i < N && A[i] > A[i - 1]) //up
				++i;
			peek = i - 1;					 //peek
			while (i < N && A[i] < A[i - 1]) //down
				++i;
			if (i - 1 < N && j != peek && i - 1 != peek)
				res = max(res, i - j);
			while (i < N && A[i] == A[i - 1]) //skip equal
				++i;
		}
		return res;
	}
};