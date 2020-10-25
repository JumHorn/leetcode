#include <vector>
using namespace std;

class Solution
{
public:
	bool canReach(vector<int> &arr, int start)
	{
		if (start < 0 || start >= (int)arr.size() || arr[start] < 0)
			return false;
		if (arr[start] == 0)
			return true;
		arr[start] = -arr[start];
		return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
	}
};