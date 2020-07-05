#include <vector>
using namespace std;

class Solution
{
public:
	bool canMakeArithmeticProgression(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());
		int gap = arr[1] - arr[0];
		for (int i = 1; i < (int)arr.size(); i++)
		{
			if (gap != arr[i] - arr[i - 1])
				return false;
		}
		return true;
	}
};
