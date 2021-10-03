#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numOfPairs(vector<string> &nums, string target)
	{
		unordered_map<string, int> m;
		for (auto &str : nums)
			++m[str];
		int N = target.size(), res = 0;
		for (int i = 1; i < N; ++i)
		{
			string lhs = target.substr(0, i);
			string rhs = target.substr(i);
			if (m.count(lhs) != 0 && m.count(rhs) != 0)
			{
				if (lhs == rhs)
				{
					int n = m[lhs];
					res += n * (n - 1);
				}
				else
					res += m[lhs] * m[rhs];
			}
		}
		return res;
	}
};