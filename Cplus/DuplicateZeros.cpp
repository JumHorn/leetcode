#include <vector>
using namespace std;

class Solution
{
public:
	void duplicateZeros(vector<int> &arr)
	{
		int i = 0, j = 0, N = arr.size();
		for (; j < N; ++i, ++j)
		{
			if (arr[i] == 0)
				++j;
		}
		if (j > N)
		{
			--i;
			j = N - 1;
			arr[j] = 0;
		}
		for (--i, --j; i >= 0; --i, --j)
		{
			if (arr[i] == 0)
				arr[j--] = 0;
			arr[j] = arr[i];
		}
	}
};