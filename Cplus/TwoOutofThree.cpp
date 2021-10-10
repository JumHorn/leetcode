#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
	{
		vector<int> v1(101), v2(101), v3(101);
		mark(nums1, v1);
		mark(nums2, v2);
		mark(nums3, v3);
		vector<int> res;
		for (int i = 0; i < 101; ++i)
		{
			if (v1[i] + v2[i] + v3[i] >= 2)
				res.push_back(i);
		}
		return res;
	}

	void mark(vector<int> &num, vector<int> &v)
	{
		for (auto n : num)
			v[n] = 1;
	}
};