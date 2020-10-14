#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int subarrayBitwiseORs(vector<int> &A)
	{
		unordered_set<int> res, dp, nextdp;
		for (auto n : A)
		{
			dp.insert(n);
			for (auto m : dp)
			{
				nextdp.insert(m | n);
				res.insert(m | n);
			}
			dp.swap(nextdp);
			nextdp.clear();
		}
		return res.size();
	}
};