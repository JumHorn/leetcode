#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> replaceElements(vector<int>& arr)
	{
		if (arr.empty())
			return arr;
		int max = arr.back();
		int i = arr.size() - 1;
		arr[i] = -1;
		for (--i; i >= 0; --i)
		{
			int tmp = arr[i];
			arr[i] = max;
			if (tmp > max)
				max = tmp;
		}
		return arr;
	}
};
