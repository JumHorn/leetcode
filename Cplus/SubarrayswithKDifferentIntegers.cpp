#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int subarraysWithKDistinct(vector<int> &A, int K)
	{
		return atMostK(A, K) - atMostK(A, K - 1);
	}

	int atMostK(vector<int> &A, int K)
	{
		unordered_map<int, int> window;
		int res = 0;
		for (int i = 0, j = 0; i < (int)A.size(); ++i)
		{
			if (++window[A[i]] == 1)
				--K;
			for (; K < 0; ++j)
			{
				if (--window[A[j]] == 0)
					++K;
			}
			res += i - j + 1;
		}
		return res;
	}
};