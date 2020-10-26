#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		unordered_set<int> s(nums1.begin(), nums1.end()), res;
		for (auto c : nums2)
		{
			if (s.find(c) != s.end())
				res.insert(c);
		}
		return {res.begin(), res.end()};
	}
};