#include <vector>
using namespace std;

class Solution
{
public:
	int findLatestStep(vector<int> &arr, int m)
	{
		int res = -1, N = arr.size();
		if (N == m)
			return N;
		vector<int> length(N + 2);
		for (int i = 0; i < N; ++i)
		{
			int a = arr[i], left = length[a - 1], right = length[a + 1];
			length[a - left] = length[a + right] = left + right + 1;
			if (left == m || right == m)
				res = i;
		}
		return res;
	}
};