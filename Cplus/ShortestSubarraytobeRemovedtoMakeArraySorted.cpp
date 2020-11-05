#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLengthOfShortestSubarray(vector<int> &arr)
	{
		int N = arr.size(), left = 0, right = N - 1;
		while (left + 1 < N && arr[left] <= arr[left + 1])
			++left;
		if (left == N - 1)
			return 0;

		while (right > left && arr[right - 1] <= arr[right])
			--right;
		//merge left,and right
		int res = min(N - left - 1, right);
		for (int i = 0, j = right; i <= left && j < N;)
		{
			if (arr[j] >= arr[i])
			{
				res = min(res, j - i - 1);
				++i;
			}
			else
				++j;
		}
		return res;
	}
};