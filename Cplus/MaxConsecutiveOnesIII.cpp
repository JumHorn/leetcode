#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestOnes(vector<int> &A, int K)
	{
		int i = 0, j = 0, n = A.size(), res = 0;
		while (i < n)
		{
			if (A[i] == 0)
			{
				if (K <= 0)
				{
					while (j <= i)
					{
						if (A[j] == 0)
							break;
						++j;
					}
					++j;
				}
				else
					--K;
			}
			i++;
			res = max(res, i - j);
		}
		return res;
	}
};