#include <unordered_map>
#include <vector>
using namespace std;

class FindSumPairs
{
public:
	FindSumPairs(vector<int> &nums1, vector<int> &nums2) : r1(nums1), r2(nums2)
	{
		for (auto n : nums2)
			++m[n];
	}

	void add(int index, int val)
	{
		--m[r2[index]];
		r2[index] += val;
		++m[r2[index]];
	}

	int count(int tot)
	{
		int res = 0;
		for (auto n : r1)
		{
			if (m.find(tot - n) != m.end())
				res += m[tot - n];
		}
		return res;
	}

private:
	unordered_map<int, int> m; //{val,count}
	vector<int> &r1, &r2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */