#include <vector>
using namespace std;

class Solution
{
public:
	bool containsPattern(vector<int> &arr, int m, int k)
	{
		int count = 0, N = arr.size();
		for (int i = 0; i + m < N; ++i)
		{
			if (arr[i] != arr[i + m])
				count = -1;
			if (++count == (k - 1) * m)
				return true;
		}
		return false;
	}
};