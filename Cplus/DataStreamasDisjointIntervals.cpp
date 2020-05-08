#include <vector>
#include <map>
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
		if (data.empty())
		{
			data[val] = val;
			return;
		}
		auto iter = data.upper_bound(val);
		if (iter == data.begin())
		{
			if (iter->first == val + 1)
			{
				data[val] = iter->second;
				data.erase(iter);
			}
			else
				data[val] = val;
		}
		else if (iter == data.end())
		{
			--iter;
			if (val <= iter->second + 1)
				data[iter->first] = max(val, iter->second);
			else
				data[val] = val;
		}
		else
		{
			auto preiter = iter;
			--preiter;
			if (preiter->second < val)
			{
				if (iter->first == val + 1 && preiter->second + 1 == val)
				{
					data[preiter->first] = iter->second;
					data.erase(iter);
				}
				else if (iter->first == val + 1)
				{
					data[val] = iter->second;
					data.erase(iter);
				}
				else if (preiter->second + 1 == val)
					data[preiter->first] = val;
				else
					data[val] = val;
			}
		}
	}

	vector<vector<int>> getIntervals()
	{
		vector<vector<int>> res;
		for (auto &n : data)
			res.push_back({n.first, n.second});
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