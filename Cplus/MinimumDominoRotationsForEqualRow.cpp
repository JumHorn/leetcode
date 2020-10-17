#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDominoRotations(vector<int> &A, vector<int> &B)
	{
		vector<int> countA(7), countB(7), same(7);
		int N = A.size();
		for (int i = 0; i < N; ++i)
		{
			++countA[A[i]];
			++countB[B[i]];
			if (A[i] == B[i])
				++same[A[i]];
		}
		for (int i = 1; i < 7; ++i)
		{
			if (countA[i] + countB[i] - same[i] == N)
				return N - max(countA[i], countB[i]);
		}
		return -1;
	}
};