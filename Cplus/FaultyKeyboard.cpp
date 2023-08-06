#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string finalString(string s)
	{
		string res;
		for (auto c : s)
		{
			if (c == 'i')
				reverse(res.begin(), res.end());
			else
				res.push_back(c);
		}
		return res;
	}
};