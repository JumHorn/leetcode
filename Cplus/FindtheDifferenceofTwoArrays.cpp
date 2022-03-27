#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
	{
		unordered_set<int> s1(nums1.begin(), nums1.end());
		unordered_set<int> s2(nums2.begin(), nums2.end());
		vector<int> v1, v2;
		for (auto n : s1)
		{
			if (s2.count(n) == 0)
				v1.push_back(n);
		}
		for (auto n : s2)
		{
			if (s1.count(n) == 0)
				v2.push_back(n);
		}
		return {v1, v2};
	}
};