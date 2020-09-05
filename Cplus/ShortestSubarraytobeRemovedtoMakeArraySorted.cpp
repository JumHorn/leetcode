#include <vector>
using namespace std;

class Solution
{
public:
	int findLengthOfShortestSubarray(vector<int> &arr)
	{
		int n = arr.size(), top = n, bottom = -1;
		if (n == 1)
			return 0;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i] < arr[i - 1])
			{
				top = min(top, i - 1);
				bottom = max(bottom, i);
			}
		}
		if (top == n)
			return 0;
		if (bottom == n - 1)
			return n - 1;
		int res = bottom - top - 1;
		int i = bottom;
		while (i < n && arr[i] < arr[top])
			++i;
		int val = i - bottom;
		i = top;
		while (i >= 0 && arr[i] > arr[bottom])
			--i;
		val = min(val, top - i);
		return res + val;
	}
};