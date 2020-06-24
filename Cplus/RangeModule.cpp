#include <algorithm>
#include <map>
using namespace std;

class RangeModule
{
public:
	RangeModule()
	{
	}

	void addRange(int left, int right)
	{
		auto iter = m.lower_bound(left);
		auto prev = iter;
		if (prev != m.begin())
		{
			--prev;
			if (prev->second >= left)
			{
				left = prev->first;
				right = max(right, prev->second);
				m.erase(prev);
			}
		}
		while (iter != m.end() && right >= iter->first)
		{
			right = max(right, iter->second);
			iter = m.erase(iter);
		}
		m[left] = right;
	}

	bool queryRange(int left, int right)
	{
		auto iter = m.lower_bound(left);
		auto prev = iter;
		if (prev != m.begin())
		{
			--prev;
			if (prev->second >= right)
				return true;
		}
		if (iter == m.end())
			return false;
		return iter->first <= left && iter->second >= right;
	}

	void removeRange(int left, int right)
	{
		auto iter = m.lower_bound(left);
		auto prev = iter;
		if (prev != m.begin())
		{
			--prev;
			if (prev->second > right)
				m[right] = prev->second;
			prev->second = min(left, prev->second);
		}
		while (iter != m.end() && right > iter->first)
		{
			if (right < iter->second)
				m[right] = iter->second;
			iter = m.erase(iter);
		}
	}

private:
	map<int, int> m; //{left,right}
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */