#include <algorithm>
#include <vector>
using namespace std;

/*
slide window
*/

class Solution
{
public:
	int longestOnes(vector<int> &A, int K)
	{
		int N = A.size(), i = 0, j = 0; //[i,j)
		for (; j < N; ++j)
		{
			if (A[j] == 0)
				--K;
			if (K < 0)
				K += 1 ^ A[i++];
		}
		return j - i;
	}
};