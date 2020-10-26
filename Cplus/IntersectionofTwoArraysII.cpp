#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
	{
		unordered_map<int, int> m;
		vector<int> res;
		for (auto c : nums1)
			++m[c];
		for (auto c : nums2)
		{
			if (m.find(c) != m.end())
			{
				if (--m[c] == 0)
					m.erase(c);
				res.push_back(c);
			}
		}
		return res;
	}
};