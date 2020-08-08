#include <vector>
using namespace std;

class Solution
{
public:
	int findKthPositive(vector<int>& arr, int k)
	{
		int N = arr.size(), res = 0;
		for (int i = 0; i < N && k > 0;)
		{
			++res;
			if (res == arr[i])
				++i;
			else
				--k;
		}
		return res + k;
	}
};
