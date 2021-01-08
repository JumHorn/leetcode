#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSubarraysWithSum(vector<int> &A, int S)
	{
		unordered_map<int, int> m({{0, 1}});
		int prefixsum = 0, res = 0;
		for (auto n : A)
		{
			prefixsum += n;
			res += m[prefixsum - S];
			++m[prefixsum];
		}
		return res;
	}
};