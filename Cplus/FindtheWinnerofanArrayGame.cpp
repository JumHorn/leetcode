#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int getWinner(vector<int>& arr, int k)
	{
		int maxwin = *max_element(arr.begin(), arr.end());
		int count = k - 1, res = max(arr[0], arr[1]);
		for (int i = 2; i < (int)arr.size() && count > 0; ++i)
		{
			if (res == maxwin)
				return res;
			if (res < arr[i])
			{
				count = k - 1;
				res = arr[i];
			}
			else
				--count;
		}
		return res;
	}
};
