#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxWidthRamp(vector<int> &A)
	{
		int res = 0;
		map<int, int> m;
		m[A[0]] = 0;
		for (int i = 1; i < (int)A.size(); i++)
		{
			if (A[i] < m.begin()->first)
				m[A[i]] = i;
			else
			{
				auto iter = m.upper_bound(A[i]);
				--iter;
				res = max(res, i - iter->second);
			}
		}
		return res;
	}
};