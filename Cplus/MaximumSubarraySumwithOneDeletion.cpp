#include <vector>
using namespace std;

class Solution
{
public:
	int maximumSum(vector<int> &arr)
	{
		int res = arr[0];
		int max1 = arr[0]; //one deletion
		int max0 = arr[0]; //no deletion
		for (int i = 1; i < (int)arr.size(); ++i)
		{
			max1 = max(max0, max(max1, 0) + arr[i]);
			max0 = max(max0, 0) + arr[i];
			res = max(res, max1);
		}
		return res;
	}
};