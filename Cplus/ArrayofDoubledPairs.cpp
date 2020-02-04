#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canReorderDoubled(vector<int> &A)
	{
		map<int, int> positive, negative;
		for (int i = 0; i < (int)A.size(); i++)
		{
			if (A[i] >= 0)
				++positive[A[i]];
			else
				++negative[-A[i]];
		}
		return doubleCheck(positive) && doubleCheck(negative);
	}

	bool doubleCheck(map<int, int> &m)
	{
		while (!m.empty())
		{
			int tmp = m.begin()->first;
			if (m.find(2 * tmp) == m.end())
				return false;
			if (--m[tmp] <= 0)
				m.erase(tmp);
			if (--m[tmp * 2] <= 0)
				m.erase(tmp * 2);
		}
		return true;
	}
};