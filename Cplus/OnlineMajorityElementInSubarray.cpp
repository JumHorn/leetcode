#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

class MajorityChecker
{
public:
	MajorityChecker(vector<int> &arr) : v(arr)
	{
		for (int i = 0; i < (int)arr.size(); ++i)
			hashmap[arr[i]].push_back(i);
	}

	int query(int left, int right, int threshold)
	{
		for (int i = 0; i < 7; ++i)
		{
			int val = v[left + rand() % (right - left + 1)];
			if (hashmap[val].size() >= threshold)
			{
				auto it1 = lower_bound(hashmap[val].begin(), hashmap[val].end(), left);
				auto it2 = upper_bound(hashmap[val].begin(), hashmap[val].end(), right);
				if (it2 - it1 >= threshold)
					return val;
			}
		}
		return -1;
	}

private:
	unordered_map<int, vector<int>> hashmap; //{value,index}
	vector<int> v;							 //same as arr
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */