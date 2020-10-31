#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> replaceElements(vector<int> &arr)
	{
		if (arr.empty())
			return arr;
		int N = arr.size(), maxsuffix = arr.back();
		arr[N - 1] = -1;
		for (int i = N - 2; i >= 0; --i)
		{
			int tmp = arr[i];
			arr[i] = maxsuffix;
			if (tmp > maxsuffix)
				maxsuffix = tmp;
		}
		return arr;
	}
};