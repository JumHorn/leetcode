#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> cellsInRange(string s)
	{
		vector<string> res;
		for (char c = s[0]; c <= s[3]; ++c)
		{
			for (char i = s[1]; i <= s[4]; ++i)
			{
				res.emplace_back();
				res.back().push_back(c);
				res.back().push_back(i);
			}
		}
		return res;
	}
};