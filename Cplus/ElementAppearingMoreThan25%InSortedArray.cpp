#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findSpecialInteger(vector<int> &arr)
	{
		int N = arr.size();
		for (int i : {N / 4, N / 2, N * 3 / 4})
		{
			auto p = equal_range(arr.begin(), arr.end(), arr[i]);
			if ((p.second - p.first) > N / 4)
				return arr[i];
		}
		return 0;
	}
};