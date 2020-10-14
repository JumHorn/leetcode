#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int subarrayBitwiseORs(vector<int> &A)
	{
		vector<int> res;
		int left = 0, right;
		for (int n : A)
		{
			right = res.size();
			res.push_back(n);
			for (int i = left; i < right; ++i)
			{
				if (res.back() != (res[i] | n))
					res.push_back(res[i] | n);
			}
			left = right;
		}
		return unordered_set<int>(res.begin(), res.end()).size();
	}
};