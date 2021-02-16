#include <algorithm>
#include <vector>
using namespace std;

//three-way partitioning

class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		three_way_partitioning(nums, 1, 1);
	}

	/* sort array into three part
	[first,mid1)
	[mid1,mid2]
	(mid3,last]
	*/
	void three_way_partitioning(vector<int> &data, int mid1, int mid2)
	{
		for (int i = 0, j = 0, k = (int)data.size() - 1; j <= k;)
		{
			if (data[j] < mid1)
				swap(data[i++], data[j++]);
			else if (data[j] > mid2)
				swap(data[j], data[k--]);
			else
				++j;
		}
	}
};