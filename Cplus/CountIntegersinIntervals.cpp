#include <map>
using namespace std;

class RangeModule
{
public:
	RangeModule()
	{
		len = 0;
	}

	void addRange(int left, int right)
	{
		const int l = left, r = right;
		len += r - l;
		auto iter = m.lower_bound(left);
		auto prev = iter;
		if (prev != m.begin())
		{
			--prev;
			if (prev->second >= left)
			{
				left = prev->first;
				right = max(right, prev->second);
				len -= intersection(l, r, prev->first, prev->second);
				m.erase(prev);
			}
		}
		while (iter != m.end() && right >= iter->first)
		{
			right = max(right, iter->second);
			len -= intersection(l, r, iter->first, iter->second);
			iter = m.erase(iter);
		}
		m[left] = right;
	}

	int countRange()
	{
		return len;
	}

	int intersection(int a, int b, int c, int d) //[a,b) [c,d)
	{
		if (b > c && a < d)
			return min(b, d) - max(a, c);
		return 0;
	}

private:
	map<int, int> m; //{left,right}
	int len;
};

class CountIntervals
{
public:
	CountIntervals()
	{
	}

	void add(int left, int right)
	{
		range.addRange(left, right + 1);
	}

	int count()
	{
		return range.countRange();
	}

private:
	RangeModule range;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */