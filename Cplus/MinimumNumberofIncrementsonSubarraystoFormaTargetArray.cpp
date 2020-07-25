#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberOperations(vector<int> &target)
	{
		int N = target.size();
		return recursion(target, 0, N - 1);
	}

	int recursion(vector<int> &target, int first, int last)
	{
		if (first > last)
			return 0;
		if (first == last)
			return target[first];
		int min = *min_element(target.begin() + first, target.begin() + last + 1);
		int res = min;
		for (int i = first; i <= last; ++i)
			target[i] -= min;
		for (int i = first, j = first; j <= last;)
		{
			while (i <= last && target[i] == 0)
				++i;
			j = i;
			while (j <= last && target[j] != 0)
				++j;
			res += recursion(target, i, j - 1);
			i = j;
		}
		return res;
	}
};