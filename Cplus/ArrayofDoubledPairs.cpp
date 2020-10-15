#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canReorderDoubled(vector<int> &A)
	{
		map<int, int> positive, negative;
		for (auto n : A)
		{
			if (n >= 0)
				++positive[n];
			else
				++negative[-n];
		}
		return doubleCheck(positive) && doubleCheck(negative);
	}

	bool doubleCheck(map<int, int> &m)
	{
		while (!m.empty())
		{
			int val = m.begin()->first;
			if (m.find(2 * val) == m.end())
				return false;
			if (--m[val] <= 0)
				m.erase(val);
			if (--m[val * 2] <= 0)
				m.erase(val * 2);
		}
		return true;
	}
};