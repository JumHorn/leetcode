#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> validStrings(int n)
	{
		unordered_set<string> dp = {"0", "1"};
		for (int i = 2; i <= n; ++i)
		{
			unordered_set<string> dp1;
			for (auto &str : dp)
			{
				if (str.back() == '1')
					dp1.insert(str + "0");
				dp1.insert(str + "1");
			}
			dp.swap(dp1);
		}
		return vector<string>(dp.begin(), dp.end());
	}
};