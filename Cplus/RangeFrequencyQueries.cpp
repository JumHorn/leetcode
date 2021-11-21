#include <algorithm>
#include <vector>
using namespace std;

class RangeFreqQuery
{
public:
	RangeFreqQuery(vector<int> &arr)
	{
		data = vector<vector<int>>(10001);
		for (int i = 0; i < (int)arr.size(); ++i)
			data[arr[i]].push_back(i);
	}

	int query(int left, int right, int value)
	{
		auto &v = data[value];
		auto l = lower_bound(v.begin(), v.end(), left);
		if (l == v.end())
			return 0;
		auto r = upper_bound(v.begin(), v.end(), right);
		return r - l;
	}

private:
	vector<vector<int>> data;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */