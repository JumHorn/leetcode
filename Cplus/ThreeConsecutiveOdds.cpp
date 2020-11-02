#include <vector>
using namespace std;

class Solution
{
public:
	bool threeConsecutiveOdds(vector<int> &arr)
	{
		int window = 0, N = arr.size();
		for (int i = 0; i < N; ++i)
		{
			window += arr[i] % 2;
			if (i >= 3)
				window -= arr[i - 3] % 2;
			if (window == 3)
				return true;
		}
		return false;
	}
};