#include <map>
#include <vector>
using namespace std;

class SummaryRanges
{
public:
	/** Initialize your data structure here. */
	SummaryRanges()
	{
	}

	void addNum(int val)
	{
		if (data.find(val) != data.end())
			return;
		data[val] = val;
		int minval = val, maxval = val;
		if (data.find(val - 1) != data.end())
			minval = data[val - 1];
		if (data.find(val + 1) != data.end())
			maxval = data[val + 1];
		data[minval] = maxval;
		data[maxval] = minval;
	}

	vector<vector<int>> getIntervals()
	{
		vector<vector<int>> res;
		auto iter = data.begin();
		for (auto iter = data.begin(); iter != data.end();)
		{
			res.push_back({iter->first, iter->second});
			iter = data.upper_bound(iter->second);
		}
		return res;
	}

private:
	map<int, int> data;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */