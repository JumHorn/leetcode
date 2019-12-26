#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int mctFromLeafValues(vector<int> &arr)
	{
		int res = 0;
		vector<pair<int, int>> v(arr.size());
		for (int i = 0; i < (int)v.size(); i++)
		{
			v[i].first = -arr[i];
			v[i].second = arr[i];
		}
		make_heap(v.begin(), v.end());
		int index = v.size() - 1;
		while (index > 0)
		{
			pop_heap(v.begin(), v.begin() + index + 1);
			pair<int, int> node1 = v[index--];
			pop_heap(v.begin(), v.begin() + index + 1);
			pair<int, int> node2 = v[index];
			res += node1.second * node2.second;
			v[index] = {node1.first + node2.first, max(node1.second, node2.second)};
			if (index > 0)
				push_heap(v.begin(), v.begin() + index);
		}
		return res;
	}
};