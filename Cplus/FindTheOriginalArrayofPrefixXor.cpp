#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findArray(vector<int> &pref)
	{
		vector<int> res;
		int val = 0;
		for (auto n : pref)
		{
			res.push_back(n ^ val);
			val = n;
		}
		return res;
	}
};