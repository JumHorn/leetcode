#include <vector>
using namespace std;

class Solution
{
public:
	bool canReach(vector<int>& arr, int start)
	{
		if (start < 0 || start >= (int)arr.size() || arr[start] == -1)
			return false;
		int tmp = arr[start];
		if (tmp == 0)
			return true;
		arr[start] = -1;
		return canReach(arr, start + tmp) || canReach(arr, start - tmp);
	}
};
