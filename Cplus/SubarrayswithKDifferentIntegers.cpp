#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int subarraysWithKDistinct(vector<int> &A, int K)
	{
		int res = 0;
		unordered_map<int, int> wk, wk_1; //window k and window k-1
		for (int i = 0, j = 0, j_1 = 0; i < (int)A.size(); i++)
		{
			++wk[A[i]];
			++wk_1[A[i]];
			if (wk_1.size() == K)
			{
				while (--wk_1[A[j_1]] != 0)
					j_1++;
				wk_1.erase(A[j_1++]);
			}
			if (wk.size() > K)
			{
				while (--wk[A[j]] != 0)
					j++;
				wk.erase(A[j++]);
			}
			if (wk.size() == K)
				res += j_1 - j;
		}
		return res;
	}
};