#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
	{
		int N = nums.size();
		vector<pair<int, int>> v; //{val,index}
		for (int i = 0; i < N; ++i)
			v.push_back({nums[i], i});
		sort(v.begin(), v.end());
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || v[i].first - v[i - 1].first > limit)
			{
				vector<int> index;
				for (int k = j; k < i; ++k)
					index.push_back(v[k].second);
				sort(index.begin(), index.end());
				for (int k = 0; j < i; ++j, ++k)
					nums[index[k]] = v[j].first;
			}
		}
		return nums;
	}
};