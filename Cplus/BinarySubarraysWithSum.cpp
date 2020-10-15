#include <unordered_map>
#include <vector>
using namespace std;

/*
slide window
add all subarray which end with i,when i updated
*/

class Solution
{
public:
	int numSubarraysWithSum(vector<int> &A, int S)
	{
		int res = 0, sum = 0, N = A.size();
		for (int i = 0, j = 0, k = 0; i < N; ++i)
		{
			sum += A[i];
			while (j < i && sum > S)
				sum -= A[j++];
			if (sum == S)
			{
				k = max(k, j);
				while (k < i && A[k] == 0)
					++k;
				res += k - j + 1;
			}
		}
		return res;
	}
};