#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
	{
		int res = 0, index = 0;
		if (ruleKey == "type")
			index = 0;
		else if (ruleKey == "color")
			index = 1;
		else
			index = 2;
		for (auto &item : items)
		{
			if (item[index] == ruleValue)
				++res;
		}
		return res;
	}
};